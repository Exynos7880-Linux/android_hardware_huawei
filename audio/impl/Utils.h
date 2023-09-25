//
// Copyright (C) 2023 The LineageOS Project
//
// SPDX-License-Identifier: Apache-2.0
//

#include <android/hardware/audio/common/4.0/types.h>
#include <android/hardware/audio/2.0/IDevice.h>
#include <android/hardware/audio/4.0/IPrimaryDevice.h>
#include <android/hardware/audio/4.0/types.h>

#define CREATE_VEC_COPY_FNS_DECL(oldType, newType) \
    hidl_vec<newType> convert(hidl_vec<oldType> oldVar); \
    hidl_vec<oldType> convert(hidl_vec<newType> newVar);

#define CREATE_COPY_FNS_DECL(oldType, newType) \
    newType convert(oldType oldVar);           \
    oldType convert(newType newVar);

#define CREATE_ALL_COPY_FNS_DECL(oldType, newType) \
    CREATE_COPY_FNS_DECL(oldType, newType)         \
    CREATE_VEC_COPY_FNS_DECL(oldType, newType)

namespace android {
namespace hardware {
namespace audio {
namespace implementation {

using ::android::hardware::hidl_vec;

V4_0::Result convert(V2_0::Result result);

CREATE_ALL_COPY_FNS_DECL(common::V2_0::AudioConfig, common::V4_0::AudioConfig)

CREATE_ALL_COPY_FNS_DECL(common::V2_0::AudioPort, common::V4_0::AudioPort)

CREATE_ALL_COPY_FNS_DECL(common::V2_0::AudioPortConfig, common::V4_0::AudioPortConfig)

CREATE_ALL_COPY_FNS_DECL(V2_0::DeviceAddress, V4_0::DeviceAddress)

CREATE_ALL_COPY_FNS_DECL(V2_0::ParameterValue, V4_0::ParameterValue)

}  // namespace implementation
}  // namespace audio
}  // namespace hardware
}  // namespace android
