// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000018.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000018[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x98,0xfb,0x97,0x8d,0x65,
    0x14,0xc7,0xdf,0x39,0xe7,0xcc,0x39,0x8c,0xdb,0xc8,0xe4,0x16,0xad,0xb9,0x20,0x35,
    0x1a,0xaa,0x71,0x77,0x30,0x94,0xa1,0xdc,0x87,0x22,0xc9,0x25,0x15,0x13,0x93,0xcc,
    0x74,0x11,0x31,0x2e,0x21,0x4a,0x24,0x95,0xa1,0x42,0x45,0x65,0x28,0x2a,0x97,0xa2,
    0xa2,0x5c,0xba,0x99,0x54,0xa8,0x08,0xf5,0x43,0xff,0x41,0xab,0xcb,0x5a,0x5d,0x9e,
    0xfd,0xcc,0x67,0x9f,0xb5,0xd7,0xbb,0x54,0xb3,0xd6,0xb3,0xde,0xb3,0xbf,0x7b,0x3f,
    0xdf,0xe7,0xbb,0xf7,0x7e,0xde,0xe7,0x39,0x67,0xa2,0x91,0xbc,0x44,0x10,0xa4,0x05,
    0x19,0x41,0x9d,0xe0,0xa7,0xa0,0xf6,0xaf,0x71,0x10,0x71,0x48,0x10,0xd4,0x0b,0xe2,
    0xfe,0x59,0x3c,0xb8,0x64,0x70,0x41,0x79,0xc5,0x94,0x82,0xc2,0xce,0x9d,0xc4,0xdf,
    0x30,0x88,0xfa,0x38,0xf1,0x35,0x0a,0x12,0x41,0xcc,0x3d,0x65,0xcc,0x98,0x34,0xad,
    0x4c,0xf0,0x76,0x6e,0x5c,0x70,0x23,0xd3,0xc5,0x09,0x9e,0x10,0x0e,0xf7,0xa9,0x9d,
    0xe7,0x94,0x39,0x41,0x30,0x30,0x48,0x0f,0x3a,0xb0,0x5e,0x1e,0x4f,0xc5,0xd2,0xc0,
    0xea,0x18,0x2c,0x02,0x96,0x69,0xb0,0x28,0x58,0x96,0xc1,0x62,0x60,0xcd,0x0d,0x96,
    0x0e,0xd6,0xca,0x60,0x71,0xb0,0x6c,0x83,0x25,0xc0,0xda,0x18,0xac,0x0e,0x58,0x7b,
    0x83,0xd5,0x05,0xeb,0x60,0xb0,0x0c,0xb0,0x4e,0x06,0xab,0x07,0x56,0x68,0xb0,0xfa,
    0x60,0xdd,0x0c,0xd6,0x00,0xac,0x97,0xaf,0x53,0x34,0x95,0xaf,0xd4,0x6c,0x9c,0x7b,
    0xe6,0x52,0x1f,0xb5,0x73,0x8c,0x2d,0x75,0xbe,0x1c,0xbb,0x89,0x9b,0x15,0xf1,0xfe,
    0xa8,0xaf,0x8d,0x7c,0x6e,0xea,0x3e,0xc5,0xc9,0x33,0xdb,0xc5,0x27,0xc8,0x33,0xee,
    0xe3,0x62,0x3e,0xbf,0x38,0x58,0xbe,0xb3,0xe3,0xe8,0xf9,0x79,0x47,0xdb,0x64,0x96,
    0x63,0x68,0x68,0xf0,0x26,0x6e,0x8c,0xdc,0x3b,0xb4,0x48,0x6d,0xa9,0xf1,0x8e,0xe2,
    0x49,0x49,0xb5,0x5b,0xba,0x91,0xcc,0x58,0xda,0x47,0x6d,0xa9,0x77,0xd5,0xba,0x16,
    0x7d,0x2f,0x75,0x76,0x36,0x1a,0xa4,0xb7,0xcd,0x9c,0x9d,0x83,0x1d,0x41,0x57,0x2e,
    0x1a,0x72,0xf0,0xb7,0x41,0x57,0x0c,0x7f,0x5b,0xe6,0x0a,0xde,0x13,0xbb,0x9d,0xe1,
    0xbb,0x82,0x78,0xe1,0x93,0xf5,0xf2,0xe1,0x0f,0x7c,0x7d,0x32,0x7d,0x4d,0x73,0x18,
    0xaa,0x25,0xff,0x7f,0x46,0x76,0xea,0x19,0x0b,0xae,0xa6,0xef,0x1d,0x58,0x5f,0xec,
    0x02,0xb0,0x7c,0xf2,0xeb,0x88,0x1e,0x89,0xef,0x84,0x2f,0xc7,0xf8,0xbb,0x98,0x7c,
    0xba,0xa6,0xe6,0xd6,0xfa,0xe5,0xd9,0x03,0xbd,0xe2,0xef,0x4d,0x3d,0xb2,0xcd,0xfc,
    0xfe,0xec,0x65,0x8d,0x1f,0xc4,0x7a,0xea,0x1f,0x4a,0xef,0xa4,0x1e,0x37,0xc3,0xad,
    0xeb,0xdd,0x02,0x9f,0xe0,0x2d,0xdc,0xca,0x63,0xf1,0xa7,0xb1,0x66,0xf8,0x29,0x73,
    0x6e,0xe5,0xf3,0x58,0x72,0x16,0x7b,0x1c,0x98,0xae,0x39,0x3e,0x64,0x4f,0xe6,0xbd,
    0x94,0xf9,0x77,0x90,0x63,0x36,0x9a,0xee,0xe2,0x73,0xd4,0xc4,0x97,0xd2,0x33,0xb5,
    0xcb,0xe8,0xa3,0xe6,0x58,0x61,0xf8,0xee,0x4f,0xed,0xd3,0x5a,0xbe,0x87,0xf8,0x6c,
    0xf9,0x2a,0x53,0x75,0x8b,0x05,0x4f,0xf3,0xb9,0x8d,0xd9,0xc3,0xcf,0x79,0xb5,0xf3,
    0xfb,0x6b,0xfc,0x06,0xde,0x53,0x5d,0x6f,0x7b,0x48,0xcf,0x2e,0xce,0x00,0xb5,0x0f,
    0x84,0x7a,0x7e,0x8c,0x77,0x5a,0xf9,0xbf,0x34,0xf5,0x10,0xfb,0x07,0x6f,0x55,0xf6,
    0x11,0x3d,0xe7,0xd1,0xaa,0x7b,0xf8,0x3c,0xe7,0x64,0xd4,0xef,0x8d,0x74,0xbf,0x6e,
    0x8c,0xf9,0x82,0xfd,0xe6,0x90,0x74,0x62,0x73,0x39,0x23,0x12,0xc6,0x2e,0x34,0xb6,
    0xf4,0x77,0x8c,0xb1,0x25,0xf7,0xb5,0xc6,0x96,0xe7,0xe6,0x90,0xbd,0x35,0x64,0x57,
    0x1b,0x5b,0xf6,0xdf,0x51,0xec,0x24,0xef,0x63,0x7b,0xde,0xb9,0x61,0x0e,0x95,0xf7,
    0xed,0x4a,0xb0,0xf6,0x66,0xef,0x94,0xf1,0x6e,0x5f,0x85,0xbf,0xc8,0x65,0x20,0xef,
    0xc2,0x35,0xbc,0x2f,0x1d,0xe1,0x93,0x98,0x6b,0xc1,0x17,0xba,0x18,0xb1,0xaf,0x63,
    0x9e,0xe0,0xbd,0x5d,0x05,0xf2,0xc0,0x34,0xbe,0x33,0x35,0x10,0x5f,0x21,0xb6,0xf0,
    0x77,0xe5,0x3c,0x2d,0xe0,0x1d,0x4b,0xd2,0xcb,0xee,0xe0,0xdb,0x5c,0x4c,0x43,0x9f,
    0x57,0x2d,0x26,0xef,0xd9,0xaf,0x8e,0x23,0x89,0xee,0x3f,0x5c,0x7c,0x4f,0xce,0xdf,
    0x24,0x75,0xef,0x05,0xb7,0xd4,0xa1,0x0f,0xb5,0xee,0x01,0xb7,0xf4,0xbd,0x2f,0xf8,
    0x3c,0xec,0x22,0x30,0x9d,0xd3,0xcf,0xcc,0x11,0xbd,0xfd,0x88,0xf9,0xdd,0x71,0xeb,
    0x1a,0x49,0xa3,0xff,0x7a,0xf4,0xf7,0x37,0xfa,0x6f,0x00,0x57,0xfd,0x03,0xc0,0x54,
    0xff,0x40,0xa3,0x7f,0x80,0xbf,0x0f,0x02,0x8f,0x09,0x77,0xb1,0xd1,0x72,0x23,0x5a,
    0x06,0x19,0xfd,0x37,0x81,0xab,0xfe,0xc1,0x60,0x3a,0x67,0x88,0x99,0x23,0xfa,0x87,
    0x10,0x23,0xfa,0x75,0x8d,0x81,0x46,0xff,0x30,0xf4,0x0f,0x35,0xfa,0x87,0x83,0xab,
    0xfe,0x11,0x60,0xaa,0xbf,0xc4,0xe8,0x17,0xdf,0x48,0x37,0x4a,0xe0,0x1e,0x69,0xfa,
    0x3e,0x0a,0x2d,0xb2,0xef,0xc4,0x1e,0x0d,0x36,0xca,0x9c,0x57,0xba,0x27,0x46,0xa3,
    0x51,0x79,0x4a,0xe0,0x91,0x33,0xec,0x36,0xce,0x2f,0xdd,0x93,0xb7,0xa3,0x79,0xbc,
    0x59,0x6b,0x02,0xb8,0xda,0x13,0x59,0xbb,0x92,0x3d,0x3a,0x89,0x98,0x89,0xf0,0xc8,
    0x19,0x37,0x05,0x9e,0xc9,0xa6,0xbe,0x77,0x82,0x8f,0x70,0x31,0x62,0xdf,0xcd,0xdc,
    0xc0,0x60,0x53,0xc1,0xd2,0x7c,0x5d,0xe2,0xfe,0x7c,0x9c,0x46,0xec,0x54,0x38,0x74,
    0x8d,0x7b,0x58,0xa3,0xd4,0xac,0x31,0x1d,0x7c,0x82,0xab,0x8b,0x9c,0xeb,0x33,0xc8,
    0x71,0x1a,0x67,0xd8,0x74,0xea,0x32,0x06,0x9f,0xf6,0xea,0x5e,0xb8,0xca,0x4c,0xaf,
    0x66,0x82,0x6b,0xaf,0xee,0x03,0xd3,0x5e,0x95,0x9b,0x5e,0x89,0x6f,0x96,0x9c,0xa2,
    0xd4,0x78,0x16,0xdc,0x72,0x3e,0x3f,0xc0,0x39,0x54,0x61,0xb8,0x1f,0x04,0x4f,0x72,
    0x2f,0xcd,0x26,0x66,0x98,0x3b,0x59,0xe5,0x0c,0x7f,0x18,0x6c,0xb6,0x39,0x47,0x22,
    0xd4,0x44,0xfc,0x73,0xe0,0xd0,0xb1,0xd8,0xad,0x25,0xf8,0x5c,0xe6,0xce,0x31,0xdc,
    0x8f,0xa4,0xb8,0xeb,0x7a,0x7b,0x1e,0xd8,0x5c,0xce,0xd6,0x74,0xee,0x97,0xa8,0xa9,
    0xcd,0x3c,0xf6,0x4c,0x39,0xf9,0xcc,0x37,0xb5,0x5a,0x40,0xad,0x2a,0x4d,0x3e,0x0b,
    0xc1,0xb5,0x56,0x8b,0xc0,0xb4,0x56,0x8f,0x9a,0x5a,0x2d,0xf2,0x7a,0x03,0x8f,0x09,
    0xf7,0x62,0x53,0xab,0x25,0x17,0xa9,0xd5,0x52,0xf0,0x6a,0xb8,0x97,0x81,0xf5,0x40,
    0xa3,0xf2,0xc8,0xf3,0x17,0xd7,0x77,0x89,0x79,0x0c,0x0d,0xf3,0x89,0x5f,0x8c,0x8e,
    0x15,0x46,0x87,0xc4,0x2c,0x77,0x63,0x05,0xf3,0x97,0x1b,0x1d,0x8f,0x5f,0x44,0xc7,
    0x13,0xe0,0x5a,0xd7,0x95,0xa1,0x9e,0x3d,0x09,0xb6,0xf2,0x5f,0x7a,0xb6,0x0a,0x0e,
    0x1d,0x4b,0xe8,0xd9,0x6a,0xe6,0xae,0x32,0xdc,0x4f,0x85,0x7a,0xb6,0x06,0x6c,0xf5,
    0x7f,0xf4,0x6c,0x0d,0xf5,0xd0,0x7c,0x56,0x84,0x7a,0x58,0x6e,0xf8,0x9f,0x81,0x7f,
    0x26,0xf7,0xd8,0xb3,0x60,0xc2,0xb5,0x16,0x5b,0xef,0xb8,0x75,0xdc,0x9b,0xc3,0x5d,
    0x6d,0xc5,0xae,0xe2,0x3b,0x83,0x1d,0xcb,0x9c,0x22,0xf1,0xad,0x27,0xbe,0xca,0x70,
    0xad,0x37,0x7b,0xe7,0x79,0xf6,0xce,0x06,0x53,0xd7,0x17,0xc0,0x75,0xef,0xbc,0x08,
    0xa6,0x7b,0x67,0x93,0xe9,0x99,0xf8,0x36,0xba,0xb1,0x89,0x9c,0x36,0xc2,0x2d,0x77,
    0xf2,0x4b,0xe8,0xd4,0x3b,0x49,0xea,0xf3,0x32,0xb8,0x68,0xd9,0x8c,0xdd,0xdd,0xc5,
    0x8b,0xef,0x15,0x7e,0xa3,0x6c,0x36,0x1c,0x5b,0x0c,0x87,0xcc,0xd9,0x42,0x9c,0xfa,
    0x5f,0xc5,0x3f,0xc8,0xac,0xf1,0x1a,0xb8,0xc4,0x6f,0xc5,0xd6,0x35,0x5e,0x67,0x8d,
    0xad,0x86,0x63,0x9b,0xe1,0x90,0x39,0xdb,0x88,0x53,0xff,0x0e,0xfc,0xdb,0xcd,0x1a,
    0x6f,0x80,0x4b,0x7c,0x35,0xb6,0xae,0xf1,0x26,0x6b,0x54,0x1b,0x8e,0x9d,0x86,0x43,
    0xe6,0xec,0x24,0x4e,0xf6,0x83,0xd6,0x6e,0x93,0xe9,0xcb,0x5b,0xf4,0x65,0x97,0xe9,
    0xcb,0xdb,0xe0,0xda,0x97,0x77,0xc0,0xb4,0x2f,0x7b,0x4c,0x5f,0xc4,0xb7,0xdb,0x8d,
    0xfd,0x70,0xef,0x36,0xfb,0x67,0x2f,0x5a,0xf4,0x3b,0xd2,0x3e,0xb0,0xbd,0xe6,0x7b,
    0x9d,0xc6,0xbe,0x9b,0x8a,0xad,0xeb,0xed,0xf7,0xc0,0xf6,0x99,0x7d,0x1f,0x31,0xfb,
    0x7e,0x2d,0x31,0x92,0xd7,0x1e,0xd6,0xde,0x6f,0xf2,0x7a,0x9f,0xbc,0x0e,0x98,0xbc,
    0x3e,0x00,0xd7,0xbc,0x3e,0x04,0xd3,0xbc,0x0e,0x99,0xbc,0xc4,0x77,0xd0,0x8d,0x23,
    0x70,0x1f,0x34,0x35,0xfe,0x08,0xad,0x15,0xa6,0x4f,0x1f,0x83,0x6b,0xcc,0xe1,0xd0,
    0x7e,0x3a,0x4c,0x8c,0xe8,0x3d,0x04,0xe7,0x11,0x73,0xa7,0x7d,0x82,0xde,0x63,0xe6,
    0x4e,0xfb,0x14,0x5c,0xe6,0x1f,0xc5,0x56,0xdf,0x67,0x7c,0x27,0x3d,0xca,0xfd,0xf9,
    0x39,0x58,0xa9,0xc9,0xef,0x0b,0xf0,0xf1,0xe4,0x57,0x63,0xf2,0x13,0xdf,0x71,0x37,
    0x6a,0xd0,0x72,0xdc,0x68,0x3f,0x11,0xda,0xa7,0x27,0xf8,0x2e,0x2f,0xda,0x35,0xbe,
    0xc6,0x68,0xf9,0x2a,0xa4,0xe5,0x6b,0xb0,0x2e,0x46,0xcb,0x37,0xe0,0xaa,0xe5,0x94,
    0xd1,0x22,0xbe,0x93,0x6e,0x9c,0x82,0xfb,0xa4,0xd1,0x72,0x3a,0xb4,0x9f,0x4f,0x1b,
    0x2d,0x1a,0x7f,0xca,0x68,0xf9,0x36,0xa4,0xe5,0x3b,0xb0,0x5d,0x46,0xcb,0xf7,0xe0,
    0xaa,0xe5,0xac,0xd1,0x22,0xbe,0x33,0x6e,0x9c,0x85,0xfb,0x8c,0xd1,0x72,0xce,0xf4,
    0x5d,0xb4,0x9c,0xe3,0x37,0x8d,0x68,0xd1,0xf8,0xb3,0xa1,0x1e,0x1f,0x0a,0xed,0xd1,
    0x3d,0x66,0xcf,0xff,0x08,0x9f,0x70,0x5d,0xc0,0xfe,0xd3,0xdd,0x1e,0xdd,0xdc,0xe8,
    0xc2,0x3b,0x9e,0x81,0x36,0xf9,0xdd,0xd5,0xd5,0xc5,0x25,0xf8,0xcd,0x25,0x5c,0xf5,
    0xcc,0xfe,0xab,0x0f,0xbe,0x9f,0x1c,0x1b,0x81,0x35,0x20,0xc7,0xc6,0x26,0xc7,0x46,
    0xfc,0xef,0xa8,0x29,0x3c,0x99,0x86,0xe7,0x12,0x78,0x96,0xb1,0x7e,0x16,0x98,0xfc,
    0xbf,0xe3,0x2f,0x17,0x9b,0xc5,0x9c,0xa6,0x66,0x4e,0x33,0xe6,0x2c,0x60,0x4e,0x0b,
    0xb0,0xe6,0x86,0xe7,0x32,0xf0,0x96,0x5e,0x57,0xc2,0x63,0xad,0xb9,0x2b,0x5b,0xe2,
    0x6f,0xc5,0x1a,0xad,0x59,0x43,0x34,0xff,0x4d,0x3d,0xfe,0x01,0x7d,0xa7,0xa9,0x3c,
    0x9c,0x13,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform utexture2DArray src;
// layout(location = 0)out vec4 dst;
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
// float sRGBToLinear(float sRGB)
// {
//
//     if(sRGB <= 0.04045)
//     {
//         return sRGB / 12.92;
//     }
//     else
//     {
//         return pow((sRGB + 0.055f)/ 1.055f, 2.4f);
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
//           uvec4 srcValue = texelFetch(src, ivec3(params . srcOffset + srcSubImageCoords, params . srcLayer), params . srcMip);
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
//            vec4 dstValue = vec4(srcValue);
//
//     dstValue /= 255.0;
//
//     if(params . dstIsSRGB)
//     {
//
//         dstValue . r = sRGBToLinear(dstValue . r);
//         dstValue . g = sRGBToLinear(dstValue . g);
//         dstValue . b = sRGBToLinear(dstValue . b);
//     }
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
