// Copyright 2019 The Dawn Authors
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

#ifndef DAWNNATIVE_METAL_UTILSMETAL_H_
#define DAWNNATIVE_METAL_UTILSMETAL_H_

#include "dawn_native/dawn_platform.h"
#include "dawn_native/metal/DeviceMTL.h"
#include "dawn_native/metal/ShaderModuleMTL.h"
#include "dawn_native/metal/TextureMTL.h"

#import <Metal/Metal.h>

namespace dawn_native {
    struct ProgrammableStage;
    struct EntryPointMetadata;
    enum class SingleShaderStage;
}

namespace dawn_native { namespace metal {

    MTLCompareFunction ToMetalCompareFunction(wgpu::CompareFunction compareFunction);

    struct TextureBufferCopySplit {
        static constexpr uint32_t kMaxTextureBufferCopyRegions = 3;

        struct CopyInfo {
            NSUInteger bufferOffset;
            NSUInteger bytesPerRow;
            NSUInteger bytesPerImage;
            Origin3D textureOrigin;
            Extent3D copyExtent;
        };

        uint32_t count = 0;
        std::array<CopyInfo, kMaxTextureBufferCopyRegions> copies;

        auto begin() const {
            return copies.begin();
        }

        auto end() const {
            return copies.begin() + count;
        }
    };

    TextureBufferCopySplit ComputeTextureBufferCopySplit(const Texture* texture,
                                                         uint32_t mipLevel,
                                                         Origin3D origin,
                                                         Extent3D copyExtent,
                                                         uint64_t bufferSize,
                                                         uint64_t bufferOffset,
                                                         uint32_t bytesPerRow,
                                                         uint32_t rowsPerImage,
                                                         Aspect aspect);

    void EnsureDestinationTextureInitialized(CommandRecordingContext* commandContext,
                                             Texture* texture,
                                             const TextureCopy& dst,
                                             const Extent3D& size);

    MTLBlitOption ComputeMTLBlitOption(const Format& format, Aspect aspect);

    // Helper function to create function with constant values wrapped in
    // if available branch
    MaybeError CreateMTLFunction(const ProgrammableStage& programmableStage,
                                 SingleShaderStage singleShaderStage,
                                 PipelineLayout* pipelineLayout,
                                 ShaderModule::MetalFunctionData* functionData,
                                 uint32_t sampleMask = 0xFFFFFFFF,
                                 const RenderPipeline* renderPipeline = nullptr);

}}  // namespace dawn_native::metal

#endif  // DAWNNATIVE_METAL_UTILSMETAL_H_
