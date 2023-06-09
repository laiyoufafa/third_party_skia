// Copyright 2020 The Dawn Authors
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

#ifndef DAWNNATIVE_QUERYSET_H_
#define DAWNNATIVE_QUERYSET_H_

#include "dawn_native/Error.h"
#include "dawn_native/Forward.h"
#include "dawn_native/ObjectBase.h"

#include "dawn_native/dawn_platform.h"

namespace dawn_native {

    MaybeError ValidateQuerySetDescriptor(DeviceBase* device, const QuerySetDescriptor* descriptor);

    class QuerySetBase : public ApiObjectBase {
      public:
        QuerySetBase(DeviceBase* device, const QuerySetDescriptor* descriptor);

        static QuerySetBase* MakeError(DeviceBase* device);

        ObjectType GetType() const override;

        wgpu::QueryType GetQueryType() const;
        uint32_t GetQueryCount() const;
        const std::vector<wgpu::PipelineStatisticName>& GetPipelineStatistics() const;

        const std::vector<bool>& GetQueryAvailability() const;
        void SetQueryAvailability(uint32_t index, bool available);

        MaybeError ValidateCanUseInSubmitNow() const;

        void APIDestroy();

      protected:
        QuerySetBase(DeviceBase* device, ObjectBase::ErrorTag tag);

        // Constructor used only for mocking and testing.
        QuerySetBase(DeviceBase* device);
        void DestroyImpl() override;

        ~QuerySetBase() override;

      private:
        MaybeError ValidateDestroy() const;

        wgpu::QueryType mQueryType;
        uint32_t mQueryCount;
        std::vector<wgpu::PipelineStatisticName> mPipelineStatistics;

        enum class QuerySetState { Unavailable, Available, Destroyed };
        QuerySetState mState = QuerySetState::Unavailable;

        // Indicates the available queries on the query set for resolving
        std::vector<bool> mQueryAvailability;
    };

}  // namespace dawn_native

#endif  // DAWNNATIVE_QUERYSET_H_
