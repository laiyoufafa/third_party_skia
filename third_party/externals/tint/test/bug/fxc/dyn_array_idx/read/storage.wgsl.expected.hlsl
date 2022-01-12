cbuffer cbuffer_ubo : register(b0, space0) {
  uint4 ubo[1];
};

RWByteAddressBuffer result : register(u2, space0);

RWByteAddressBuffer ssbo : register(u1, space0);

[numthreads(1, 1, 1)]
void f() {
  result.Store(0u, asuint(asint(ssbo.Load((4u * uint(asint(ubo[0].x)))))));
  return;
}
