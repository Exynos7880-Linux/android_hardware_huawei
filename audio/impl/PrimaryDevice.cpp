//
// Copyright (C) 2023 The LineageOS Project
//
// SPDX-License-Identifier: Apache-2.0
//

#include "PrimaryDevice.h"

#include "Utils.h"

namespace android::hardware::audio::implementation {

PrimaryDevice::PrimaryDevice(V2_0::IPrimaryDevice* device) : mDevice(device) {}

Return<V4_0::Result> PrimaryDevice::initCheck() {
    return convert(mDevice->initCheck());
}

Return<V4_0::Result> PrimaryDevice::setMasterVolume(float volume) {
    return convert(mDevice->setMasterVolume(volume));
}

Return<void> PrimaryDevice::getMasterVolume(getMasterVolume_cb _hidl_cb) {
    return mDevice->getMasterVolume(
        [&](V2_0::Result result, float volume) {
            _hidl_cb(convert(result), volume);
        }
    );
}

Return<V4_0::Result> PrimaryDevice::setMicMute(bool mute) {
    return convert(mDevice->setMicMute(mute));
}

Return<void> PrimaryDevice::getMicMute(getMicMute_cb _hidl_cb) {
    return mDevice->getMicMute(
        [&](V2_0::Result result, bool mute) {
            _hidl_cb(convert(result), mute);
        }
    );
}

Return<V4_0::Result> PrimaryDevice::setMasterMute(bool mute) {
    return convert(mDevice->setMasterMute(mute));
}

Return<void> PrimaryDevice::getMasterMute(getMasterMute_cb _hidl_cb) {
    return mDevice->getMasterMute(
        [&](V2_0::Result result, bool mute) {
            _hidl_cb(convert(result), mute);
        }
    );
}

Return<void> PrimaryDevice::getInputBufferSize(const common::V4_0::AudioConfig& config,
                                getInputBufferSize_cb _hidl_cb) {
    return mDevice->getInputBufferSize(
        convert(config),
        [&](V2_0::Result result, uint64_t bufferSize) {
            _hidl_cb(convert(result), bufferSize);
        }
    );
}

Return<void> PrimaryDevice::openOutputStream(int32_t ioHandle, const V4_0::DeviceAddress& device,
                                const common::V4_0::AudioConfig& config,
                                hidl_bitfield<common::V4_0::AudioOutputFlag> flags,
                                const V4_0::SourceMetadata& sourceMetadata,
                                openOutputStream_cb _hidl_cb) {
    return mDevice->openOutputStream(ioHandle, convert(device), convert(config), flags, sourceMetadata, _hidl_cb);
}

Return<void> PrimaryDevice::openInputStream(int32_t ioHandle, const V4_0::DeviceAddress& device,
                                const common::V4_0::AudioConfig& config,
                                hidl_bitfield<common::V4_0::AudioInputFlag> flags,
                                const V4_0::SinkMetadata& sinkMetadata,
                                openInputStream_cb _hidl_cb) {
    return mDevice->openInputStream(ioHandle, convert(device), convert(config), flags, sinkMetadata, _hidl_cb);
}

Return<bool> PrimaryDevice::supportsAudioPatches() {
    return mDevice->supportsAudioPatches();
}

Return<void> PrimaryDevice::createAudioPatch(const hidl_vec<common::V4_0::AudioPortConfig>& sources,
                                const hidl_vec<common::V4_0::AudioPortConfig>& sinks,
                                createAudioPatch_cb _hidl_cb) {
    return mDevice->createAudioPatch(
        convert(sources), convert(sinks),
        [&](V2_0::Result result, int32_t patch) {
            _hidl_cb(convert(result), patch);
        }
    );
}

Return<V4_0::Result> PrimaryDevice::releaseAudioPatch(int32_t patch) {
    return convert(mDevice->releaseAudioPatch(patch));
}

Return<void> PrimaryDevice::getAudioPort(const common::V4_0::AudioPort& port, getAudioPort_cb _hidl_cb) {
    return mDevice->getAudioPort(
        convert(port),
        [&](V2_0::Result result, const common::V2_0::AudioPort& port) {
            _hidl_cb(convert(result), convert(port));
        }
    );
}

Return<V4_0::Result> PrimaryDevice::setAudioPortConfig(const common::V4_0::AudioPortConfig& config) {
    return convert(mDevice->setAudioPortConfig(convert(config)));
}


Return<V4_0::Result> PrimaryDevice::setScreenState(bool turnedOn) {
    return convert(mDevice->setScreenState(turnedOn));
}


Return<void> PrimaryDevice::getHwAvSync(getHwAvSync_cb _hidl_cb) {
    _hidl_cb(V4_0::Result::OK, mDevice->getHwAvSync());
    return Void();
}

Return<void> PrimaryDevice::getParameters(const hidl_vec<V4_0::ParameterValue>& /*context*/,
                            const hidl_vec<hidl_string>& keys,
                            getParameters_cb _hidl_cb) {
    return mDevice->getParameters(
        keys,
        [&](V2_0::Result result, const hidl_vec<V2_0::ParameterValue>& parameters) {
            _hidl_cb(convert(result), convert(parameters));
        }
    );
}

Return<V4_0::Result> PrimaryDevice::setParameters(const hidl_vec<V4_0::ParameterValue>& /*context*/,
                                const hidl_vec<V4_0::ParameterValue>& parameters) {
    return convert(mDevice->setParameters(convert(parameters)));
}

Return<void> PrimaryDevice::getMicrophones(getMicrophones_cb _hidl_cb) {
    return mDevice->getMicrophones(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setConnectedState(const V4_0::DeviceAddress& address, bool connected) {
    return convert(mDevice->setConnectedState(address, connected));
}

Return<void> PrimaryDevice::debug(const hidl_handle& fd, const hidl_vec<hidl_string>& options) {
    return mDevice->debug(fd, options);
}

Return<V4_0::Result> PrimaryDevice::setVoiceVolume(float volume) {
    return convert(mDevice->setVoiceVolume(volume));
}

Return<V4_0::Result> PrimaryDevice::setMode(common::V4_0::AudioMode mode) {
    return convert(mDevice->setMode(mode));
}

Return<void> PrimaryDevice::getBtScoNrecEnabled(getBtScoNrecEnabled_cb _hidl_cb) {
    return mDevice->getBtScoNrecEnabled(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setBtScoNrecEnabled(bool enabled) {
    return convert(mDevice->setBtScoNrecEnabled(enabled));
}

Return<void> PrimaryDevice::getBtScoWidebandEnabled(getBtScoWidebandEnabled_cb _hidl_cb) {
    return mDevice->getBtScoWidebandEnabled(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setBtScoWidebandEnabled(bool enabled) {
    return convert(mDevice->setBtScoWidebandEnabled(enabled));
}

Return<void> PrimaryDevice::getTtyMode(getTtyMode_cb _hidl_cb) {
    return mDevice->getTtyMode(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setTtyMode(V4_0::IPrimaryDevice::TtyMode mode) {
    return convert(mDevice->setTtyMode(mode));
}

Return<void> PrimaryDevice::getHacEnabled(getHacEnabled_cb _hidl_cb) {
    return mDevice->getHacEnabled(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setHacEnabled(bool enabled) {
    return convert(mDevice->setHacEnabled(enabled));
}

Return<V4_0::Result> PrimaryDevice::setBtScoHeadsetDebugName(const hidl_string& name) {
    return convert(mDevice->setBtScoHeadsetDebugName(name));
}

Return<void> PrimaryDevice::getBtHfpEnabled(getBtHfpEnabled_cb _hidl_cb) {
    return mDevice->getBtHfpEnabled(_hidl_cb);
}

Return<V4_0::Result> PrimaryDevice::setBtHfpEnabled(bool enabled) {
    return convert(mDevice->setBtHfpEnabled(enabled));
}

Return<V4_0::Result> PrimaryDevice::setBtHfpSampleRate(uint32_t sampleRateHz) {
    return convert(mDevice->setBtHfpSampleRate(sampleRateHz));
}

Return<V4_0::Result> PrimaryDevice::setBtHfpVolume(float volume) {
    return convert(mDevice->setBtHfpVolume(volume));
}

Return<V4_0::Result> PrimaryDevice::updateRotation(V4_0::IPrimaryDevice::Rotation rotation) {
    return convert(mDevice->updateRotation(rotation));
}

}  // namespace android::hardware::audio::implementation
