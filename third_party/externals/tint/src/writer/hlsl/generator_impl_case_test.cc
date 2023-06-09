// Copyright 2020 The Tint Authors.
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

#include "src/ast/fallthrough_statement.h"
#include "src/writer/hlsl/test_helper.h"

namespace tint {
namespace writer {
namespace hlsl {
namespace {

using HlslGeneratorImplTest_Case = TestHelper;

TEST_F(HlslGeneratorImplTest_Case, Emit_Case) {
  auto* s = Switch(1, Case(Expr(5), Block(create<ast::BreakStatement>())),
                   DefaultCase());
  WrapInFunction(s);

  GeneratorImpl& gen = Build();

  gen.increment_indent();

  ASSERT_TRUE(gen.EmitCase(s, 0)) << gen.error();
  EXPECT_EQ(gen.result(), R"(  case 5: {
    break;
  }
)");
}

TEST_F(HlslGeneratorImplTest_Case, Emit_Case_BreaksByDefault) {
  auto* s = Switch(1, Case(Expr(5), Block()), DefaultCase());
  WrapInFunction(s);

  GeneratorImpl& gen = Build();

  gen.increment_indent();

  ASSERT_TRUE(gen.EmitCase(s, 0)) << gen.error();
  EXPECT_EQ(gen.result(), R"(  case 5: {
    break;
  }
)");
}

TEST_F(HlslGeneratorImplTest_Case, Emit_Case_WithFallthrough) {
  auto* s =
      Switch(1,                                                          //
             Case(Expr(4), Block(create<ast::FallthroughStatement>())),  //
             Case(Expr(5), Block(create<ast::ReturnStatement>())),       //
             DefaultCase());
  WrapInFunction(s);

  GeneratorImpl& gen = Build();

  gen.increment_indent();

  ASSERT_TRUE(gen.EmitCase(s, 0)) << gen.error();
  EXPECT_EQ(gen.result(), R"(  case 4: {
    /* fallthrough */
    {
      return;
    }
    break;
  }
)");
}

TEST_F(HlslGeneratorImplTest_Case, Emit_Case_MultipleSelectors) {
  auto* s =
      Switch(1, Case({Expr(5), Expr(6)}, Block(create<ast::BreakStatement>())),
             DefaultCase());
  WrapInFunction(s);

  GeneratorImpl& gen = Build();

  gen.increment_indent();

  ASSERT_TRUE(gen.EmitCase(s, 0)) << gen.error();
  EXPECT_EQ(gen.result(), R"(  case 5:
  case 6: {
    break;
  }
)");
}

TEST_F(HlslGeneratorImplTest_Case, Emit_Case_Default) {
  auto* s = Switch(1, DefaultCase(Block(create<ast::BreakStatement>())));
  WrapInFunction(s);

  GeneratorImpl& gen = Build();

  gen.increment_indent();

  ASSERT_TRUE(gen.EmitCase(s, 0)) << gen.error();
  EXPECT_EQ(gen.result(), R"(  default: {
    break;
  }
)");
}

}  // namespace
}  // namespace hlsl
}  // namespace writer
}  // namespace tint
