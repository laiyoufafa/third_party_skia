// Copyright 2021 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/resolver/resolver.h"

#include "src/sem/constant.h"
#include "src/sem/type_constructor.h"
#include "src/utils/map.h"

namespace tint {
namespace resolver {
namespace {

using i32 = ProgramBuilder::i32;
using u32 = ProgramBuilder::u32;
using f32 = ProgramBuilder::f32;

}  // namespace

sem::Constant Resolver::EvaluateConstantValue(const ast::Expression* expr,
                                              const sem::Type* type) {
  if (auto* e = expr->As<ast::LiteralExpression>()) {
    return EvaluateConstantValue(e, type);
  }
  if (auto* e = expr->As<ast::CallExpression>()) {
    return EvaluateConstantValue(e, type);
  }
  return {};
}

sem::Constant Resolver::EvaluateConstantValue(
    const ast::LiteralExpression* literal,
    const sem::Type* type) {
  if (auto* lit = literal->As<ast::SintLiteralExpression>()) {
    return {type, {lit->ValueAsI32()}};
  }
  if (auto* lit = literal->As<ast::UintLiteralExpression>()) {
    return {type, {lit->ValueAsU32()}};
  }
  if (auto* lit = literal->As<ast::FloatLiteralExpression>()) {
    return {type, {lit->value}};
  }
  if (auto* lit = literal->As<ast::BoolLiteralExpression>()) {
    return {type, {lit->value}};
  }
  TINT_UNREACHABLE(Resolver, builder_->Diagnostics());
  return {};
}

sem::Constant Resolver::EvaluateConstantValue(const ast::CallExpression* call,
                                              const sem::Type* type) {
  auto* vec = type->As<sem::Vector>();

  // For now, only fold scalars and vectors
  if (!type->is_scalar() && !vec) {
    return {};
  }

  auto* elem_type = vec ? vec->type() : type;
  int result_size = vec ? static_cast<int>(vec->Width()) : 1;

  // For zero value init, return 0s
  if (call->args.empty()) {
    if (elem_type->Is<sem::I32>()) {
      return sem::Constant(type, sem::Constant::Scalars(result_size, 0));
    }
    if (elem_type->Is<sem::U32>()) {
      return sem::Constant(type, sem::Constant::Scalars(result_size, 0u));
    }
    if (elem_type->Is<sem::F32>()) {
      return sem::Constant(type, sem::Constant::Scalars(result_size, 0.f));
    }
    if (elem_type->Is<sem::Bool>()) {
      return sem::Constant(type, sem::Constant::Scalars(result_size, false));
    }
  }

  // Build value for type_ctor from each child value by casting to
  // type_ctor's type.
  sem::Constant::Scalars elems;
  for (auto* expr : call->args) {
    auto* arg = builder_->Sem().Get(expr);
    if (!arg || !arg->ConstantValue()) {
      return {};
    }
    auto cast = ConstantCast(arg->ConstantValue(), elem_type);
    elems.insert(elems.end(), cast.Elements().begin(), cast.Elements().end());
  }

  // Splat single-value initializers
  if (elems.size() == 1) {
    for (int i = 0; i < result_size - 1; ++i) {
      elems.emplace_back(elems[0]);
    }
  }

  return sem::Constant(type, std::move(elems));
}

sem::Constant Resolver::ConstantCast(const sem::Constant& value,
                                     const sem::Type* target_elem_type) {
  if (value.ElementType() == target_elem_type) {
    return value;
  }

  sem::Constant::Scalars elems;
  for (size_t i = 0; i < value.Elements().size(); ++i) {
    if (target_elem_type->Is<sem::I32>()) {
      elems.emplace_back(
          value.WithScalarAt(i, [](auto&& s) { return static_cast<i32>(s); }));
    } else if (target_elem_type->Is<sem::U32>()) {
      elems.emplace_back(
          value.WithScalarAt(i, [](auto&& s) { return static_cast<u32>(s); }));
    } else if (target_elem_type->Is<sem::F32>()) {
      elems.emplace_back(
          value.WithScalarAt(i, [](auto&& s) { return static_cast<f32>(s); }));
    } else if (target_elem_type->Is<sem::Bool>()) {
      elems.emplace_back(
          value.WithScalarAt(i, [](auto&& s) { return static_cast<bool>(s); }));
    }
  }

  auto* target_type =
      value.Type()->Is<sem::Vector>()
          ? builder_->create<sem::Vector>(target_elem_type,
                                          static_cast<uint32_t>(elems.size()))
          : target_elem_type;

  return sem::Constant(target_type, elems);
}

}  // namespace resolver
}  // namespace tint
