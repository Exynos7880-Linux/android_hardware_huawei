//
// Copyright (C) 2023 The LineageOS Project
//
// SPDX-License-Identifier: Apache-2.0
//

#include "Utils.h"

#define CREATE_COPY_FN(oldType, newType)          \
    newType convert(oldType oldVar) {             \
        newType newVar;                           \
        memcpy(&newVar, &oldVar, sizeof(oldVar)); \
        return newVar;                            \
    }

#define CREATE_VEC_COPY_FN(oldType, newType)              \
    hidl_vec<newType> convert(hidl_vec<oldType> oldVar) { \
        hidl_vec<newType> newVar;                         \
        newVar.resize(oldVar.size());                     \
        for (size_t i = 0; i < oldVar.size(); i++) {      \
            newVar[i] = convert(oldVar[i]);               \
        }                                                 \
        return newVar;                                    \
    }

#define CREATE_VEC_COPY_FNS(oldType, newType) \
    CREATE_VEC_COPY_FN(oldType, newType)      \
    CREATE_VEC_COPY_FN(newType, oldType)

#define CREATE_COPY_FNS(oldType, newType) \
    CREATE_COPY_FN(oldType, newType)      \
    CREATE_COPY_FN(newType, oldType)

#define CREATE_ALL_COPY_FN(oldType, newType) \
    CREATE_COPY_FNS(oldType, newType)        \
    CREATE_VEC_COPY_FNS(oldType, newType)

namespace android::hardware::audio::implementation {

V4_0::Result convert(V2_0::Result result) {
    switch (result) {
        case V2_0::Result::OK:
            return V4_0::Result::OK;
        case V2_0::Result::NOT_INITIALIZED:
            return V4_0::Result::NOT_INITIALIZED;
        case V2_0::Result::INVALID_ARGUMENTS:
            return V4_0::Result::INVALID_ARGUMENTS;
        case V2_0::Result::INVALID_STATE:
            return V4_0::Result::INVALID_STATE;
        case V2_0::Result::NOT_SUPPORTED:
            return V4_0::Result::NOT_SUPPORTED;
        default:
            return V4_0::Result::INVALID_ARGUMENTS;
    }
}

CREATE_ALL_COPY_FN(common::V2_0::AudioConfig, common::V4_0::AudioConfig)

CREATE_ALL_COPY_FN(common::V2_0::AudioPort, common::V4_0::AudioPort)

CREATE_ALL_COPY_FN(common::V2_0::AudioPortConfig, common::V4_0::AudioPortConfig)

CREATE_ALL_COPY_FN(V2_0::DeviceAddress, V4_0::DeviceAddress)

CREATE_ALL_COPY_FN(V2_0::ParameterValue, V4_0::ParameterValue)

}  // namespace android::hardware::audio::implementation
