#version 310 es
precision mediump float;

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void f() {
  uint a = 4u;
  uvec3 b = uvec3(1u, 2u, 3u);
  uvec3 r = (a / b);
  return;
}
void main() {
  f();
}


