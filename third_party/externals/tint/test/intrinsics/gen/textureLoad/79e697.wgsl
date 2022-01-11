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

[[group(1), binding(0)]] var arg_0: texture_2d_array<i32>;

// fn textureLoad(texture: texture_2d_array<i32>, coords: vec2<i32>, array_index: i32, level: i32) -> vec4<i32>
fn textureLoad_79e697() {
  var res: vec4<i32> = textureLoad(arg_0, vec2<i32>(), 1, 0);
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureLoad_79e697();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureLoad_79e697();
}

[[stage(compute), workgroup_size(1)]]
fn compute_main() {
  textureLoad_79e697();
}
