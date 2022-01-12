Texture2D arg_0 : register(t0, space1);
SamplerComparisonState arg_1 : register(s1, space1);

void textureSampleCompareLevel_f8121c() {
  float res = arg_0.SampleCmpLevelZero(arg_1, float2(0.0f, 0.0f), 1.0f, int2(0, 0));
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  textureSampleCompareLevel_f8121c();
  return float4(0.0f, 0.0f, 0.0f, 0.0f);
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  textureSampleCompareLevel_f8121c();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  textureSampleCompareLevel_f8121c();
  return;
}
