// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000015.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000015[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x96,0x8b,0x53,0x55,0x55,
    0x14,0x87,0x0f,0xf7,0xc2,0xbd,0x08,0xf2,0x10,0x50,0x42,0xc5,0xf2,0x41,0x0f,0x31,
    0xc4,0x42,0x33,0x01,0x95,0x8c,0x24,0xa3,0x54,0x34,0x2b,0xb1,0x08,0x03,0x4b,0x4c,
    0xd3,0x24,0x4d,0xca,0x67,0x0a,0x96,0x56,0x52,0x3e,0x7a,0x89,0x95,0x68,0x25,0x62,
    0xfd,0x17,0xfd,0x45,0x4d,0x8f,0x99,0x66,0xda,0xeb,0xdc,0x6f,0x31,0xbf,0x39,0x63,
    0xc5,0xcc,0x9e,0x73,0xf6,0xb7,0xd7,0x5e,0xfb,0xb7,0x1e,0x67,0x5f,0xd2,0xa9,0x85,
    0xd9,0x28,0xca,0x8b,0x8a,0xa2,0xc2,0xe8,0x97,0x28,0xf7,0x37,0x23,0x4a,0x05,0x12,
    0x45,0xc5,0x51,0x26,0x7e,0xae,0xef,0xdc,0xd2,0xd9,0x70,0x70,0xb0,0xaf,0xa1,0x69,
    0x79,0xa3,0xad,0x97,0x46,0xe9,0xd8,0xce,0xd6,0xca,0xa2,0x6c,0x94,0x1f,0x9e,0x36,
    0xf6,0xf6,0xee,0xde,0x67,0xbc,0x24,0x8c,0x3b,0x61,0x94,0x07,0x3b,0xe3,0x59,0xf3,
    0x11,0xde,0x4a,0x62,0x9f,0xb6,0x27,0x8a,0x3a,0xa2,0x82,0xa8,0x92,0xf3,0x16,0xf2,
    0x74,0x96,0x07,0x2b,0x14,0x96,0x82,0x95,0x0b,0x4b,0xc3,0xaa,0x84,0xe5,0xc3,0xee,
    0x11,0x56,0x00,0x9b,0x2b,0x2c,0x03,0xbb,0x4f,0x58,0x16,0xb6,0x48,0x58,0x21,0xec,
    0x41,0x61,0xd3,0x60,0x4b,0x84,0x15,0xc1,0x1a,0x85,0x15,0xc3,0x9a,0x84,0x4d,0x87,
    0xad,0x14,0x56,0x02,0x6b,0x89,0xf3,0x94,0x9e,0x8a,0xd7,0x72,0xb6,0x2e,0x3c,0x17,
    0x90,0x1f,0x9f,0xcf,0x97,0xb9,0xe5,0x79,0x1e,0xf3,0xca,0xb0,0x2b,0x15,0xaf,0xa7,
    0xe3,0xdc,0xd8,0xfb,0xcc,0x60,0x93,0x21,0x4e,0xcb,0x6b,0x75,0x98,0x67,0x89,0x3f,
    0x15,0xf3,0xfc,0x38,0xc6,0x2c,0x63,0x56,0xd8,0x59,0x84,0xbd,0xd9,0x16,0x13,0x5b,
    0x3e,0xb6,0xd3,0xf1,0x63,0xbc,0x99,0x79,0x89,0xf8,0x2e,0xc5,0xde,0xcf,0xae,0xc0,
    0x57,0x14,0xeb,0x2c,0x9f,0xca,0xb3,0x6b,0xb0,0x51,0xf1,0x3f,0xc3,0x6d,0xec,0xfc,
    0x2a,0xf2,0x5f,0xc9,0xf9,0x55,0xf1,0x39,0x39,0x56,0x4f,0xac,0xb3,0xd0,0x63,0xf6,
    0xd5,0xac,0x65,0x65,0xbd,0x56,0xe2,0x99,0xc7,0x7a,0x45,0xdc,0x47,0xa9,0x38,0xb7,
    0xf5,0xe8,0xf6,0xbc,0x9b,0xdd,0xfd,0xa2,0xd9,0xfd,0xd4,0xd3,0x5b,0x6e,0xbf,0x8c,
    0x73,0x7d,0x7d,0x05,0xb9,0xb1,0xbc,0xac,0x66,0xaf,0x9f,0xbb,0x06,0x7f,0xc6,0x6b,
    0x82,0x82,0x36,0xd6,0xf3,0x38,0x33,0xf9,0xb4,0x3d,0x4f,0xf0,0xde,0x46,0xec,0x36,
    0x5f,0x07,0xf3,0x33,0xdb,0x13,0xf3,0x0d,0x7c,0x27,0xb6,0xff,0x19,0x62,0xcd,0xa0,
    0xe9,0x39,0xde,0xd3,0x62,0xdf,0x45,0xed,0x7c,0xbe,0x4d,0x62,0xb6,0x18,0x77,0x24,
    0xec,0x77,0x25,0x72,0x7b,0x92,0x6f,0xc6,0xe7,0xe7,0x13,0xb5,0xb9,0xc2,0x37,0xe0,
    0xfe,0x6e,0x48,0x1f,0x4e,0xe2,0x7b,0x35,0xf1,0x4d,0x72,0x8f,0xa4,0xe3,0x5c,0x16,
    0xc4,0x76,0xf9,0xc4,0x67,0xec,0x8f,0x40,0x0a,0xb0,0x2d,0x94,0x3a,0xfb,0x7c,0x8e,
    0xcc,0x2d,0xdf,0x6b,0x13,0xf3,0x21,0x99,0x5b,0x7d,0x2f,0x33,0x6f,0xa5,0xef,0xcb,
    0xa8,0xdf,0xc6,0x40,0x4b,0xb9,0x7b,0xca,0x18,0x5e,0x9b,0x7d,0x7c,0x4f,0x33,0x58,
    0x6f,0x0b,0x8a,0xaa,0xb9,0x7f,0x66,0xd2,0x8b,0xad,0xd8,0xd4,0xc0,0x4f,0x05,0x1b,
    0x9b,0xcf,0x66,0x5f,0x4d,0x1c,0x73,0x3a,0xd6,0x3f,0x5b,0xec,0xe7,0x12,0x93,0xad,
    0xcd,0x61,0x6e,0xfe,0xad,0x67,0xef,0xc5,0x7f,0x2d,0xf6,0xfe,0x9d,0x19,0x9f,0x08,
    0x36,0xf3,0xe5,0x7e,0xb3,0x3e,0xfe,0x3d,0xf8,0xa8,0x43,0xf7,0x5f,0xc1,0xde,0xef,
    0xb9,0x3a,0xf2,0xb8,0x08,0xdf,0x96,0x87,0x07,0xc8,0xdd,0x02,0x7c,0x67,0xb8,0xff,
    0x8c,0x1f,0x63,0xfe,0x10,0xcc,0xf7,0x2c,0x96,0x3d,0xa6,0x77,0x31,0x36,0x7f,0x06,
    0xdf,0x7e,0x46,0x9d,0xe8,0x5f,0x82,0xfe,0x7a,0xd1,0xff,0x30,0xdc,0xf5,0x37,0xc0,
    0x5c,0x7f,0xa3,0xe8,0xb7,0xb5,0xa5,0xdc,0xb7,0xe6,0x7b,0xa9,0x68,0x79,0x04,0x2d,
    0xcb,0x44,0xff,0xa3,0x70,0xd7,0xdf,0x04,0xf3,0x3d,0xcb,0x65,0x8f,0xe9,0x5f,0x8e,
    0x8d,0xe9,0xf7,0x33,0x1a,0x45,0xff,0x63,0xe8,0x5f,0x21,0xfa,0x57,0xc2,0x5d,0xff,
    0xe3,0x30,0xd7,0xdf,0x2c,0xfa,0x6d,0x6d,0x55,0xdc,0x7b,0x39,0xdf,0xab,0xa4,0xee,
    0x2d,0x68,0xb1,0xbe,0xcb,0xf5,0x63,0x8e,0xb5,0xc8,0x7d,0xe0,0x3d,0xd1,0x8a,0x46,
    0xf7,0xd3,0x8c,0x1f,0xbb,0x23,0x9e,0xe4,0x7e,0xf0,0x9e,0x7c,0x0a,0xcd,0xed,0x72,
    0xd6,0x7a,0xb8,0xcf,0x3b,0x38,0xfb,0x04,0x3d,0xfa,0x34,0x36,0x1d,0xf8,0xb1,0x3b,
    0xa4,0x13,0x3f,0x1b,0x24,0xbf,0xcf,0xc2,0x37,0x07,0x9b,0x4c,0xac,0x3d,0xb7,0x37,
    0x12,0xb6,0x09,0x96,0x17,0xbf,0x67,0xe2,0xfb,0x67,0x33,0xb6,0x9b,0xf0,0xe1,0x67,
    0x6c,0xe1,0x8c,0x2e,0x39,0x63,0x2b,0xbc,0x27,0x28,0xb3,0x3b,0xe2,0x79,0x62,0xdc,
    0xcc,0x1d,0xb2,0x95,0xbc,0xac,0x65,0xcd,0x6b,0xf5,0x02,0xbe,0xb6,0x49,0xad,0x5e,
    0x84,0x7b,0xad,0x5e,0x82,0x79,0xad,0xba,0xa5,0x56,0xb6,0xb6,0x3d,0x8c,0x7e,0x72,
    0xbc,0x5d,0xfa,0xe6,0x65,0xee,0x95,0x1d,0xa2,0xf3,0x15,0x78,0x2b,0xf7,0x7e,0x0f,
    0x36,0x1b,0xc3,0xad,0x64,0x31,0xbf,0x0a,0xeb,0x91,0x7b,0x24,0x25,0x39,0xe9,0xc5,
    0x87,0x8f,0xd3,0xe1,0x2c,0xe3,0x3b,0xd9,0xdb,0x2b,0xbe,0x5f,0x9b,0xf2,0x3d,0x2d,
    0x9e,0xf7,0xc1,0x76,0x72,0x57,0x16,0xc8,0x1d,0xef,0xb9,0xe9,0xa3,0x67,0xba,0x89,
    0xa7,0x5f,0x72,0xf5,0x3a,0xb9,0xda,0x25,0xb9,0x7a,0x03,0xee,0xb9,0xda,0x0d,0xf3,
    0x5c,0xed,0x91,0x5c,0xd9,0xda,0x40,0x18,0x7b,0xf0,0x3d,0x20,0xb9,0x7a,0xf3,0x2e,
    0xb9,0xda,0x0b,0x9f,0xc4,0xf7,0x3e,0x58,0x3b,0x1a,0xdd,0x8f,0x3d,0x7f,0x0b,0x75,
    0x37,0x9b,0xb7,0xd0,0xd0,0x8f,0xfd,0x00,0x3a,0x0e,0x88,0x0e,0xb3,0xd9,0x1f,0xc6,
    0x01,0xf6,0xef,0x17,0x1d,0x6f,0xdf,0x45,0xc7,0x41,0xb8,0xe7,0x75,0x30,0x51,0xb3,
    0x77,0x60,0x83,0xff,0x52,0xb3,0x43,0xf8,0xf0,0x31,0x42,0xcd,0x0e,0xb3,0xf7,0x90,
    0xf8,0x7e,0x37,0x51,0xb3,0x23,0xb0,0xc3,0xff,0x51,0xb3,0x23,0xe4,0xc3,0xe3,0x39,
    0x90,0xa8,0x61,0xb7,0xf8,0x7f,0x0f,0xff,0xfe,0xdd,0xbd,0x0f,0xd3,0x6f,0xf1,0x28,
    0x2c,0x4f,0xd8,0x31,0x58,0x4a,0xd8,0x71,0x58,0x3a,0x8e,0x35,0xf7,0xdd,0x9d,0xc0,
    0xe7,0x51,0xf6,0x1c,0x47,0xe7,0x10,0x6b,0xde,0x4b,0xa7,0xe8,0xa5,0x93,0xd2,0x4b,
    0x1f,0xc0,0xbd,0x97,0x4e,0xc3,0xbc,0x97,0x86,0xa5,0x86,0xb6,0x76,0x26,0x8c,0x73,
    0xc4,0x78,0x46,0x62,0x1c,0xe1,0xf7,0xdb,0xef,0xc8,0xb3,0xb0,0x11,0xf9,0xff,0xc0,
    0x6d,0x3f,0x9c,0xb2,0xcd,0xe5,0xfb,0x23,0xd8,0x59,0xc9,0x77,0x4a,0xf2,0x3d,0x84,
    0x8d,0xe5,0x77,0x98,0xb3,0xcf,0x49,0x5c,0x1f,0x13,0xd7,0x79,0x89,0xeb,0x13,0xb8,
    0xc7,0xf5,0x29,0xcc,0xe3,0x1a,0x95,0xb8,0x6c,0xed,0x42,0x18,0x97,0xf0,0x7d,0x41,
    0x7a,0xf3,0x33,0xb4,0x6a,0x6f,0x7e,0x0e,0x77,0x9b,0x8b,0xd8,0xf8,0x6f,0xed,0x45,
    0x6c,0x4c,0xef,0x28,0x3e,0x2f,0xc9,0x5d,0xfa,0x05,0x7a,0xaf,0x88,0xcf,0x2f,0xe1,
    0xb6,0xff,0x32,0x73,0x5f,0xfb,0x8a,0xff,0x85,0x7e,0xa5,0x07,0xbe,0x86,0x75,0x49,
    0x7c,0xdf,0xc0,0xdb,0x89,0x6f,0x4c,0xe2,0xb3,0xb5,0xab,0x61,0x8c,0xa1,0xe5,0xaa,
    0x68,0xbf,0x86,0x76,0xff,0x9d,0xbd,0x26,0xdf,0xba,0xdb,0x8f,0x89,0x96,0x6f,0x13,
    0x5a,0xbe,0x83,0xd5,0x8a,0x96,0xef,0xe1,0xae,0x65,0x5c,0xb4,0xd8,0xda,0xf5,0x30,
    0xc6,0xf1,0x7d,0x5d,0xb4,0xdc,0x44,0xcb,0x0d,0xb4,0xdc,0x14,0x2d,0x6e,0x3f,0x2e,
    0x5a,0x7e,0x48,0x68,0xf9,0x11,0x76,0x52,0xb4,0xfc,0x04,0x77,0x2d,0x13,0xa2,0xc5,
    0xd6,0x6e,0xc5,0xb6,0x39,0xdf,0xb7,0x44,0xcb,0x6d,0xa9,0xbb,0x69,0xb9,0xcd,0xff,
    0x8e,0xa6,0xc5,0xed,0x27,0x12,0x35,0x1e,0x4d,0xf4,0xe8,0xb0,0xf4,0xfc,0xcf,0xf8,
    0x33,0x5f,0x77,0x98,0xff,0x1d,0xbe,0xf6,0x95,0x61,0xfc,0x03,0xe2,0x08,0x57,0x4f,
    0xf4,0x0f,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform itexture2DArray src;
// layout(location = 0)out ivec4 dst;
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
//           ivec4 srcValue = texelFetch(src, ivec3(params . srcOffset + srcSubImageCoords, params . srcLayer), params . srcMip);
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
//            ivec4 dstValue = ivec4(srcValue);
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
