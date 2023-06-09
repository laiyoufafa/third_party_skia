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

#ifndef DAWNNATIVE_BINDGROUPLAYOUT_H_
#define DAWNNATIVE_BINDGROUPLAYOUT_H_

#include "common/Constants.h"
#include "common/Math.h"
#include "common/SlabAllocator.h"
#include "common/ityp_span.h"
#include "common/ityp_vector.h"
#include "dawn_native/BindingInfo.h"
#include "dawn_native/CachedObject.h"
#include "dawn_native/Error.h"
#include "dawn_native/Forward.h"
#include "dawn_native/ObjectBase.h"

#include "dawn_native/dawn_platform.h"

#include <bitset>
#include <map>

namespace dawn_native {

    MaybeError ValidateBindGroupLayoutDescriptor(DeviceBase* device,
                                                 const BindGroupLayoutDescriptor* descriptor,
                                                 bool allowInternalBinding = false);

    // Bindings are specified as a |BindingNumber| in the BindGroupLayoutDescriptor.
    // These numbers may be arbitrary and sparse. Internally, Dawn packs these numbers
    // into a packed range of |BindingIndex| integers.
    class BindGroupLayoutBase : public ApiObjectBase, public CachedObject {
      public:
        BindGroupLayoutBase(DeviceBase* device,
                            const BindGroupLayoutDescriptor* descriptor,
                            PipelineCompatibilityToken pipelineCompatibilityToken,
                            ApiObjectBase::UntrackedByDeviceTag tag);
        BindGroupLayoutBase(DeviceBase* device,
                            const BindGroupLayoutDescriptor* descriptor,
                            PipelineCompatibilityToken pipelineCompatibilityToken);
        ~BindGroupLayoutBase() override;

        static BindGroupLayoutBase* MakeError(DeviceBase* device);

        ObjectType GetType() const override;

        // A map from the BindingNumber to its packed BindingIndex.
        using BindingMap = std::map<BindingNumber, BindingIndex>;

        const BindingInfo& GetBindingInfo(BindingIndex bindingIndex) const {
            ASSERT(!IsError());
            ASSERT(bindingIndex < mBindingInfo.size());
            return mBindingInfo[bindingIndex];
        }
        const BindingMap& GetBindingMap() const;
        bool HasBinding(BindingNumber bindingNumber) const;
        BindingIndex GetBindingIndex(BindingNumber bindingNumber) const;

        // Functions necessary for the unordered_set<BGLBase*>-based cache.
        size_t ComputeContentHash() override;

        struct EqualityFunc {
            bool operator()(const BindGroupLayoutBase* a, const BindGroupLayoutBase* b) const;
        };

        BindingIndex GetBindingCount() const;
        // Returns |BindingIndex| because buffers are packed at the front.
        BindingIndex GetBufferCount() const;
        // Returns |BindingIndex| because dynamic buffers are packed at the front.
        BindingIndex GetDynamicBufferCount() const;
        uint32_t GetUnverifiedBufferCount() const;

        // Used to get counts and validate them in pipeline layout creation. Other getters
        // should be used to get typed integer counts.
        const BindingCounts& GetBindingCountInfo() const;

        // Tests that the BindingInfo of two bind groups are equal,
        // ignoring their compatibility groups.
        bool IsLayoutEqual(const BindGroupLayoutBase* other,
                           bool excludePipelineCompatibiltyToken = false) const;
        PipelineCompatibilityToken GetPipelineCompatibilityToken() const;

        struct BufferBindingData {
            uint64_t offset;
            uint64_t size;
        };

        struct BindingDataPointers {
            ityp::span<BindingIndex, BufferBindingData> const bufferData = {};
            ityp::span<BindingIndex, Ref<ObjectBase>> const bindings = {};
            ityp::span<uint32_t, uint64_t> const unverifiedBufferSizes = {};
        };

        // Compute the amount of space / alignment required to store bindings for a bind group of
        // this layout.
        size_t GetBindingDataSize() const;
        static constexpr size_t GetBindingDataAlignment() {
            static_assert(alignof(Ref<ObjectBase>) <= alignof(BufferBindingData), "");
            return alignof(BufferBindingData);
        }

        BindingDataPointers ComputeBindingDataPointers(void* dataStart) const;

        bool IsStorageBufferBinding(BindingIndex bindingIndex) const;

      protected:
        // Constructor used only for mocking and testing.
        BindGroupLayoutBase(DeviceBase* device);
        void DestroyImpl() override;

        template <typename BindGroup>
        SlabAllocator<BindGroup> MakeFrontendBindGroupAllocator(size_t size) {
            return SlabAllocator<BindGroup>(
                size,  // bytes
                Align(sizeof(BindGroup), GetBindingDataAlignment()) + GetBindingDataSize(),  // size
                std::max(alignof(BindGroup), GetBindingDataAlignment())  // alignment
            );
        }

      private:
        BindGroupLayoutBase(DeviceBase* device, ObjectBase::ErrorTag tag);

        BindingCounts mBindingCounts = {};
        ityp::vector<BindingIndex, BindingInfo> mBindingInfo;

        // Map from BindGroupLayoutEntry.binding to packed indices.
        BindingMap mBindingMap;

        // Non-0 if this BindGroupLayout was created as part of a default PipelineLayout.
        const PipelineCompatibilityToken mPipelineCompatibilityToken =
            PipelineCompatibilityToken(0);
    };

}  // namespace dawn_native

#endif  // DAWNNATIVE_BINDGROUPLAYOUT_H_
