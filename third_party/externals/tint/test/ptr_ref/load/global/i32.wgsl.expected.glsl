#version 310 es
precision mediump float;

int I = 0;

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void tint_symbol() {
  int use = (I + 1);
  return;
}
void main() {
  tint_symbol();
}


