#version 310 es
precision mediump float;

struct S {
  int i;
};

void main_1() {
  S V = S(0);
  V.i = 5;
  return;
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void tint_symbol() {
  main_1();
  return;
}
void main() {
  tint_symbol();
}


