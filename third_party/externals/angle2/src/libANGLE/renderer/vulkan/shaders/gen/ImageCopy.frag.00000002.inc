// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000002.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000002[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x98,0x87,0x73,0x55,0x55,
    0x10,0xc6,0x6f,0x92,0x97,0x17,0x08,0x2d,0x48,0x04,0x44,0x70,0x12,0x40,0x44,0x83,
    0x01,0x35,0x74,0x42,0x55,0x8a,0xd2,0x24,0x44,0x10,0x51,0x88,0x22,0x4a,0x15,0xa4,
    0xa9,0x20,0x25,0xd2,0x04,0x44,0x50,0x14,0x14,0x41,0x10,0x44,0x11,0x89,0xa0,0xa0,
    0x10,0x91,0x62,0xa1,0xa8,0x80,0x4a,0xd3,0x3f,0xc4,0xb1,0xcc,0x58,0xce,0xde,0xfc,
    0xf6,0xf9,0xf9,0x86,0xd1,0xcc,0x9c,0xb9,0x6f,0xbf,0xdd,0xfd,0xce,0xb7,0x7b,0xca,
    0x7d,0x2f,0x59,0x99,0xad,0x72,0xa2,0x28,0x23,0xca,0x8d,0x6a,0x45,0x3f,0x45,0x35,
    0x7f,0x0d,0xa3,0xcc,0x80,0x44,0x51,0x9d,0x28,0x19,0x3f,0x07,0x0c,0x2e,0x1b,0x5c,
    0x3c,0x6b,0xf6,0x84,0xe2,0x92,0x8e,0x1d,0xcc,0x5f,0x3f,0xca,0x8a,0xe3,0xcc,0xd7,
    0x20,0xca,0x89,0x12,0xe1,0x69,0x63,0x5a,0xc5,0xa4,0xe9,0x86,0xb7,0x09,0xe3,0x4a,
    0x18,0x79,0x21,0xce,0xf0,0x1c,0xe3,0x08,0x9f,0xda,0xc4,0x9c,0x96,0x13,0x45,0x03,
    0xa3,0xec,0xa8,0x1d,0xf3,0xb5,0xe2,0xe9,0x58,0x06,0x58,0x2d,0xc1,0x32,0xc1,0xf2,
    0x04,0xcb,0x02,0xcb,0x17,0x2c,0x01,0xd6,0x54,0xb0,0x6c,0xb0,0xe6,0x82,0x25,0xc1,
    0x0a,0x04,0xcb,0x01,0x6b,0x2d,0x58,0x2d,0xb0,0xb6,0x82,0xd5,0x06,0x6b,0x27,0x58,
    0x2e,0x58,0x07,0xc1,0xea,0x80,0x95,0x08,0x56,0x17,0xac,0x8b,0x60,0xf5,0xc0,0x7a,
    0xc4,0x7d,0xca,0x4a,0xd5,0x6b,0x3d,0x1b,0x13,0x9e,0x2d,0xe9,0x8f,0xdb,0x85,0x62,
    0x5b,0x9f,0x6f,0xc0,0x6e,0x14,0xb2,0x32,0x63,0x7f,0x56,0xdc,0x1b,0xfb,0xdc,0x38,
    0x7c,0x4a,0x52,0x67,0x41,0x88,0xcf,0xa1,0xce,0x64,0x1c,0x97,0x88,0xeb,0x4b,0x82,
    0x15,0x05,0x3b,0x89,0x9e,0xe6,0xc5,0x43,0xba,0xe7,0x07,0x86,0xfa,0x82,0x37,0x0a,
    0x63,0xc4,0xa1,0xa1,0x7d,0xdc,0xb6,0x1e,0x97,0x97,0x5f,0xea,0xe9,0x76,0xb3,0x30,
    0x4a,0x73,0x57,0xf4,0x72,0xdb,0xfa,0x5d,0x35,0xa0,0xa2,0xf4,0xda,0x60,0x17,0xa0,
    0xc1,0xd6,0xb6,0x49,0xb0,0x0b,0xb1,0x33,0xd1,0xd5,0x12,0x0d,0x85,0xf8,0x5b,0xa3,
    0x2b,0x81,0xff,0x46,0x72,0x0d,0xef,0x8e,0xdd,0x46,0xf8,0x6e,0x22,0xde,0xf8,0x6c,
    0xbe,0x22,0xf8,0xa3,0xb8,0x3f,0x79,0x71,0x4f,0x0b,0x19,0xae,0xa5,0xe8,0x7f,0x46,
    0x41,0xea,0x99,0x88,0x6e,0x65,0xdd,0xdb,0x31,0xbf,0xd9,0xc5,0x60,0x45,0xd4,0xd7,
    0x1e,0x3d,0x16,0xdf,0x01,0x5f,0xa1,0xf8,0x3b,0x49,0x3d,0x9d,0x53,0xb9,0x35,0x7e,
    0x7b,0x76,0x43,0xaf,0xf9,0x7b,0xd2,0x8f,0x02,0xc9,0xef,0xc7,0x5e,0xf6,0xf8,0x41,
    0xcc,0xe7,0xfe,0xa1,0xac,0x9d,0xe5,0xdf,0x47,0xbe,0xf5,0xeb,0xba,0x30,0xd3,0x68,
    0xfa,0x93,0x11,0xfd,0xfb,0x2f,0x43,0xe6,0xbc,0x9f,0xcf,0xa3,0xa9,0xd1,0xec,0x31,
    0x60,0x3e,0xc7,0xd8,0x34,0xbb,0x42,0xd6,0xf0,0x61,0x6a,0x52,0xcd,0x13,0x39,0x1b,
    0xae,0x79,0x1e,0xf1,0xee,0x5f,0x80,0x2e,0xf7,0x57,0x72,0xae,0x6d,0x4d,0x97,0xe1,
    0xcb,0x92,0xf8,0x35,0x69,0x7b,0x75,0x83,0xe8,0x31,0x7b,0x7b,0x6c,0x2d,0xea,0x67,
    0xf9,0x3b,0xe9,0xaf,0xf7,0xfc,0x6d,0x72,0x77,0x0a,0xdf,0x6e,0xce,0xb8,0xc5,0x7f,
    0x40,0xbc,0xea,0x3b,0x98,0xaa,0x29,0x11,0x7d,0x9a,0x9a,0xfb,0x1f,0xff,0x09,0xce,
    0xb4,0xf9,0x2f,0xa3,0x75,0x27,0xfd,0xbb,0xcc,0x3d,0x98,0x15,0xaf,0x7d,0x76,0xcc,
    0x9b,0x40,0xaf,0x61,0xbf,0x06,0x24,0x9b,0xd8,0x96,0xdc,0x01,0x39,0x62,0x97,0x88,
    0x6d,0xeb,0x39,0x4a,0x6c,0x7b,0x4e,0x4d,0xb3,0x67,0xa6,0xd9,0x73,0xc5,0xb6,0xda,
    0x77,0x89,0x6d,0xfb,0xeb,0x38,0x76,0x29,0xe7,0xad,0x2d,0x67,0x6a,0x58,0x40,0xed,
    0x3c,0xdd,0x0c,0xd6,0x56,0xf6,0xca,0x74,0xce,0xee,0x2d,0xf8,0xfb,0x84,0x0a,0x6c,
    0xaf,0xdf,0xc6,0x79,0x68,0x0f,0x9f,0xc5,0xdc,0x0e,0x5e,0x19,0x62,0xcc,0xbe,0x83,
    0x3c,0xc3,0x7b,0x86,0x0e,0xb4,0x02,0xf3,0xf8,0x8e,0xf4,0xc0,0x7c,0x25,0xd8,0xc6,
    0xdf,0x99,0xfb,0xb2,0x98,0x33,0x54,0xca,0x5e,0xe9,0x0a,0xbe,0x27,0xc4,0xd4,0x8f,
    0xeb,0xaa,0xc1,0xec,0x1c,0xfd,0x12,0x38,0x4a,0xd1,0xfd,0x7b,0x88,0xef,0xce,0xfd,
    0x5a,0x4a,0xdf,0x7b,0xc0,0x6d,0x7d,0xe8,0x45,0xaf,0xbb,0xc1,0x6d,0xeb,0xda,0x1b,
    0x7c,0x21,0x76,0x1f,0x30,0xcf,0xe9,0x2b,0x39,0xa6,0xb7,0x2f,0x31,0xbf,0x05,0x6e,
    0x9f,0xa3,0x54,0xf4,0xdf,0x89,0xfe,0x7e,0xa2,0xff,0x2e,0x70,0xd7,0xdf,0x1f,0xcc,
    0xf5,0x0f,0x14,0xfd,0xfd,0xe3,0xfb,0x3e,0x8a,0x31,0xe3,0x1e,0x20,0x5a,0xee,0x46,
    0xcb,0x20,0xd1,0x7f,0x0f,0xb8,0xeb,0x1f,0x0c,0xe6,0x39,0x43,0x24,0xc7,0xf4,0x0f,
    0x21,0xc6,0xf4,0xfb,0x1c,0x03,0x45,0xff,0x30,0xf4,0x0f,0x15,0xfd,0xc3,0xc1,0x5d,
    0xff,0xbd,0x60,0xae,0xbf,0x4c,0xf4,0x9b,0x6f,0x44,0x18,0x65,0x70,0x8f,0x90,0x75,
    0x1f,0x89,0x16,0xdb,0x77,0x66,0x97,0x83,0x8d,0x94,0xfb,0xc9,0xf7,0x44,0x39,0x1a,
    0x9d,0xa7,0x0c,0x1e,0xbb,0xb3,0x1e,0xe0,0xbe,0xf2,0x3d,0xf9,0x20,0x9a,0xc7,0xca,
    0x5c,0x0f,0x81,0xbb,0x3d,0x8e,0xb9,0x17,0xb3,0x47,0xc7,0x13,0x33,0x0e,0x1e,0xbb,
    0xd3,0x1e,0x81,0xa7,0x42,0xfa,0x3b,0x01,0x7c,0x5c,0xd0,0x6c,0x67,0xe7,0x51,0xe6,
    0x1f,0xcf,0xfd,0x31,0x01,0xcd,0xa3,0xf0,0x79,0x1f,0x1f,0x83,0x6b,0xa2,0xf4,0xf1,
    0x71,0x70,0xef,0xe3,0x24,0x30,0xef,0xe3,0x14,0xe9,0xa3,0xf9,0x26,0x87,0x31,0x85,
    0xfa,0x27,0xc3,0x6d,0xe7,0x78,0x1a,0x77,0x84,0xef,0xe3,0x64,0x7c,0x5e,0x6b,0x70,
    0xd3,0x32,0x15,0xbb,0x6b,0x88,0x37,0xdf,0x13,0xdc,0xcd,0x53,0x85,0x63,0x86,0x70,
    0x58,0xce,0x0c,0xe2,0xdc,0xff,0x24,0xfe,0x41,0x32,0xc7,0x2c,0x70,0x8b,0x9f,0x89,
    0xed,0x73,0xcc,0x66,0x8e,0x99,0xc2,0x31,0x47,0x38,0x2c,0x67,0x0e,0x71,0xee,0x7f,
    0x0a,0xff,0x3c,0x99,0xe3,0x69,0x70,0x8b,0x9f,0x8b,0xed,0x73,0x3c,0xc3,0x1c,0x73,
    0x85,0x63,0xbe,0x70,0x58,0xce,0x7c,0xe2,0x6c,0xef,0x78,0xef,0xa6,0xc8,0xba,0x3c,
    0xcb,0xba,0x2c,0x90,0x75,0x59,0x08,0xee,0xeb,0xb2,0x08,0xcc,0xd7,0x65,0x89,0xac,
    0xcb,0xa2,0x78,0x0f,0x45,0xd1,0x6a,0xb8,0x17,0x8b,0x96,0xe7,0xd0,0x52,0x29,0xf5,
    0x2c,0x05,0xf7,0xbb,0x77,0x39,0x31,0xc3,0xc2,0xdb,0xc8,0xde,0x7b,0x2b,0xc0,0x96,
    0xcb,0xdd,0x6b,0xfb,0x6a,0x6d,0xe0,0x34,0xff,0x4a,0x62,0x96,0x0a,0xc7,0xf3,0x29,
    0x8e,0xda,0xb1,0xbd,0x0a,0x6c,0x25,0xef,0x9d,0x6c,0x79,0x9f,0xfa,0xde,0x5c,0x45,
    0x4f,0x96,0xa0,0x7b,0xb5,0xf4,0xe4,0x05,0x7a,0xb2,0x46,0x7a,0xb2,0x16,0xdc,0x7b,
    0xf2,0x22,0x98,0xf7,0x64,0xbd,0xf4,0xc4,0x7c,0xeb,0xc2,0x58,0x0f,0xf7,0x3a,0xe9,
    0xc9,0x4b,0x57,0xe9,0xc9,0xcb,0xe0,0xd5,0x70,0xbf,0x02,0xb6,0x01,0x8d,0xce,0x63,
    0xcf,0x9f,0x03,0x8b,0xc5,0xbc,0x8a,0x86,0xd5,0xc4,0xaf,0x43,0xc7,0x26,0xd1,0x61,
    0x31,0x1b,0xc3,0xd8,0x44,0xfe,0x46,0xd1,0xf1,0xda,0x55,0x74,0xbc,0x0e,0xee,0x7d,
    0xdd,0x9c,0xb6,0x36,0x6f,0x80,0x6d,0x4e,0x5b,0x9b,0xe1,0x21,0xdb,0xfc,0x5b,0xe0,
    0xf0,0xb1,0x92,0x35,0xdb,0x4a,0xee,0x16,0xe1,0x7e,0x33,0x6d,0xcd,0xb6,0x81,0x6d,
    0xfd,0x8f,0x35,0xdb,0x46,0x3f,0xbc,0x9e,0x4d,0x69,0x6b,0xb8,0x44,0xf8,0xdf,0x82,
    0xdf,0xf6,0x8d,0xd9,0x3b,0xc0,0xb6,0x0b,0xdf,0x0e,0x89,0x7f,0x87,0xf8,0x69,0x7c,
    0x7f,0x7a,0x17,0xcc,0x62,0x77,0x61,0xfb,0xfe,0x78,0x8f,0xfd,0xb1,0x5b,0xf6,0xc7,
    0x1e,0x70,0xdf,0x1f,0xef,0x83,0xf9,0xfe,0xa8,0x92,0x75,0x31,0xdf,0xde,0x30,0x0e,
    0xa0,0x7b,0x2f,0x3c,0x36,0xef,0x3e,0xbe,0xaf,0xd8,0x3b,0xc1,0xbe,0x97,0xed,0x07,
    0xdb,0x27,0xdf,0x9f,0x3c,0xf6,0xc3,0x54,0x6c,0xed,0xd8,0xfe,0x08,0x6c,0xbf,0xf4,
    0x30,0x53,0x7a,0xb8,0x8b,0x18,0xeb,0x59,0x15,0x73,0x1f,0x90,0xba,0x3e,0xa6,0xae,
    0x83,0x52,0xd7,0x27,0xe0,0x5e,0xd7,0x21,0x30,0xaf,0xab,0x5a,0xea,0x32,0xdf,0xe1,
    0x30,0x8e,0xc1,0x7d,0x18,0x6e,0xfb,0xfe,0x78,0x04,0xad,0x95,0xc2,0xfd,0x19,0xb8,
    0xc7,0x1c,0x25,0xc6,0xef,0xe0,0xa3,0xc4,0x98,0xde,0x6a,0x38,0x8f,0xc9,0xfb,0xe9,
    0x73,0xf4,0x9e,0x90,0xf7,0xd3,0x17,0xe0,0x96,0x7f,0x1c,0xdb,0x7d,0x5f,0xf2,0xdd,
    0xef,0x54,0xc8,0x37,0xfb,0x2b,0xb0,0x0a,0xa9,0xef,0x24,0xf8,0x58,0xea,0x3b,0x2d,
    0xf5,0x9d,0x8c,0x73,0xa3,0x18,0x33,0x2d,0xa7,0x44,0xfb,0x19,0xb4,0xfb,0xdd,0x7e,
    0x86,0x3a,0x4c,0xbb,0xc7,0x9f,0x16,0x2d,0x5f,0xa7,0x69,0xf9,0x06,0xac,0x93,0x68,
    0xf9,0x16,0xdc,0xb5,0x9c,0x13,0x2d,0xe6,0x3b,0x1b,0xc6,0x39,0xb8,0xcf,0x8a,0x96,
    0xf3,0x68,0xf1,0x77,0xc0,0x79,0xd1,0xe2,0xf1,0xe7,0x44,0xcb,0x77,0x69,0x5a,0xbe,
    0x07,0xdb,0x2d,0x5a,0x7e,0x00,0x77,0x2d,0x17,0x45,0x8b,0xf9,0x2e,0x84,0x71,0x11,
    0xee,0x0b,0xa2,0xe5,0x92,0xac,0xbb,0x69,0xb9,0x44,0x8f,0x4c,0x8b,0xc7,0x5f,0x4c,
    0x5b,0xe3,0xea,0xb4,0x3d,0x5a,0x25,0x7b,0xfe,0x47,0xf8,0x8c,0xeb,0x0a,0xf6,0x1f,
    0xe1,0x26,0xea,0x12,0x46,0x27,0xde,0x8b,0xb9,0x68,0xb3,0xdf,0x37,0x9d,0x43,0x5c,
    0x0e,0xbf,0x65,0x8c,0xab,0x8e,0xdc,0x77,0x75,0xc1,0x8f,0x50,0x63,0x03,0xb0,0x7a,
    0xd4,0xd8,0x50,0x6a,0x6c,0xc0,0xff,0x60,0x1a,0xc3,0x93,0x27,0x3c,0xd7,0xc0,0xb3,
    0x8c,0xf9,0xf3,0xc1,0xec,0xff,0x06,0x7f,0x86,0xd8,0x7c,0x72,0x1a,0x4b,0x4e,0x13,
    0x72,0xea,0x06,0x75,0xc9,0xf8,0xb7,0x6a,0xcd,0x7d,0xda,0x0c,0x5f,0x53,0xe1,0xbb,
    0x1e,0x7f,0xb3,0xf8,0xdd,0x59,0x83,0xb5,0x00,0x6f,0xce,0x1c,0x2d,0x98,0xc3,0x34,
    0xff,0x45,0x3f,0xfe,0x06,0x12,0xa7,0x78,0x03,0xe4,0x12,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform texture2D src;
// layout(location = 0)out uvec4 dst;
//
// layout(push_constant)uniform PushConstants {
//
//     ivec2 srcOffset;
//     ivec2 dstOffset;
//     int srcMip;
//     int srcLayer;
//
//     bool flipX;
//     bool flipY;
//
//     bool premultiplyAlpha;
//     bool unmultiplyAlpha;
//
//     bool dstHasLuminance;
//     bool dstIsAlpha;
//
//     bool srcIsSRGB;
//     bool dstIsSRGB;
//
//     int dstDefaultChannelsMask;
//     bool rotateXY;
// } params;
//
// float linearToSRGB(float linear)
// {
//
//     if(linear <= 0.0031308)
//     {
//         return linear * 12.92;
//     }
//     else
//     {
//         return pow(linear,(1.0f / 2.4f))* 1.055f - 0.055f;
//     }
// }
//
// void main()
// {
//     ivec2 dstSubImageCoords = ivec2(gl_FragCoord . xy)- params . dstOffset;
//
//     ivec2 srcSubImageCoords = dstSubImageCoords;
//
//     if(params . flipX)
//     {
//         srcSubImageCoords . x = - srcSubImageCoords . x;
//     }
//     if(params . flipY)
//     {
//         srcSubImageCoords . y = - srcSubImageCoords . y;
//     }
//     if(params . rotateXY)
//     {
//         srcSubImageCoords . xy = srcSubImageCoords . yx;
//     }
//
//           vec4 srcValue = texelFetch(src, params . srcOffset + srcSubImageCoords, params . srcMip);
//
//     if(params . srcIsSRGB)
//     {
//
//         srcValue . r = linearToSRGB(srcValue . r);
//         srcValue . g = linearToSRGB(srcValue . g);
//         srcValue . b = linearToSRGB(srcValue . b);
//     }
//
//     if(params . premultiplyAlpha)
//     {
//         srcValue . rgb *= srcValue . a;
//     }
//     else if(params . unmultiplyAlpha && srcValue . a > 0)
//     {
//         srcValue . rgb /= srcValue . a;
//     }
//
//     srcValue *= 255.0;
//
//            uvec4 dstValue = uvec4(srcValue);
//
//     if(params . dstHasLuminance)
//     {
//         dstValue . rg = dstValue . ra;
//     }
//     else if(params . dstIsAlpha)
//     {
//         dstValue . r = dstValue . a;
//     }
//     else
//     {
//         int defaultChannelsMask = params . dstDefaultChannelsMask;
//         if((defaultChannelsMask & 2)!= 0)
//         {
//             dstValue . g = 0;
//         }
//         if((defaultChannelsMask & 4)!= 0)
//         {
//             dstValue . b = 0;
//         }
//         if((defaultChannelsMask & 8)!= 0)
//         {
//             dstValue . a = 1;
//         }
//     }
//
//     dst = dstValue;
// }
