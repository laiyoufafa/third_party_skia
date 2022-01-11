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

////////////////////////////////////////////////////////////////////////////////
// File generated by tools/intrinsic-gen
// using the template:
//   test/intrinsics/intrinsics.wgsl.tmpl
// and the intrinsic defintion file:
//   src/intrinsics.def
//
// Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

[[group(1), binding(1)]] var arg_1: texture_2d_array<i32>;
[[group(1), binding(2)]] var arg_2: sampler;

// fn textureGather(component: i32, texture: texture_2d_array<i32>, sampler: sampler, coords: vec2<f32>, array_index: i32, offset: vec2<i32>) -> vec4<i32>
fn textureGather_4f2350() {
  var res: vec4<i32> = textureGather(1, arg_1, arg_2, vec2<f32>(), 1, vec2<i32>());
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureGather_4f2350();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureGather_4f2350();
}

[[stage(compute), workgroup_size(1)]]
fn compute_main() {
  textureGather_4f2350();
}
