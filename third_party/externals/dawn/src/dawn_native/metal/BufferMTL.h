// Copyright 2017 The Dawn Authors
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

#ifndef DAWNNATIVE_METAL_BUFFERMTL_H_
#define DAWNNATIVE_METAL_BUFFERMTL_H_

#include "common/NSRef.h"
#include "common/SerialQueue.h"
#include "dawn_native/Buffer.h"

#import <Metal/Metal.h>

namespace dawn_native { namespace metal {

    class CommandRecordingContext;
    class Device;

    class Buffer final : public BufferBase {
      public:
        static ResultOrError<Ref<Buffer>> Create(Device* device,
                                                 const BufferDescriptor* descriptor);
        id<MTLBuffer> GetMTLBuffer() const;

        bool EnsureDataInitialized(CommandRecordingContext* commandContext);
        bool EnsureDataInitializedAsDestination(CommandRecordingContext* commandContext,
                                                uint64_t offset,
                                                uint64_t size);
        bool EnsureDataInitializedAsDestination(CommandRecordingContext* commandContext,
                                                const CopyTextureToBufferCmd* copy);

        static uint64_t QueryMaxBufferLength(id<MTLDevice> mtlDevice);

      private:
        using BufferBase::BufferBase;
        MaybeError Initialize(bool mappedAtCreation);

        ~Buffer() override;
        MaybeError MapAsyncImpl(wgpu::MapMode mode, size_t offset, size_t size) override;
        void UnmapImpl() override;
        void DestroyImpl() override;
        void* GetMappedPointerImpl() override;
        bool IsCPUWritableAtCreation() const override;
        MaybeError MapAtCreationImpl() override;

        void InitializeToZero(CommandRecordingContext* commandContext);
        void ClearBuffer(CommandRecordingContext* commandContext,
                         uint8_t clearValue,
                         uint64_t offset = 0,
                         uint64_t size = 0);

        NSPRef<id<MTLBuffer>> mMtlBuffer;
    };

}}  // namespace dawn_native::metal

#endif  // DAWNNATIVE_METAL_BUFFERMTL_H_
