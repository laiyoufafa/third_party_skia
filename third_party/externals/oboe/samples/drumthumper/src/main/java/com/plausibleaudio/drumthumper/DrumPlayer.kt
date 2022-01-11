/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.plausiblesoftware.drumthumper

import android.content.res.AssetManager
import android.util.Log
import java.io.IOException

class DrumPlayer {
    companion object {
        // Sample attributes
        val NUM_PLAY_CHANNELS: Int = 2  // The number of channels in the player Stream.
                                        // Stereo Playback, set to 1 for Mono playback
                                        // This IS NOT the channel format of the source samples
                                        // (which must be mono).
        val NUM_SAMPLE_CHANNELS: Int = 1;   // All WAV resource must be mono

        // Sample Buffer IDs
        val BASSDRUM: Int = 0
        val SNAREDRUM: Int = 1
        val CRASHCYMBAL: Int = 2
        val RIDECYMBAL: Int = 3
        val MIDTOM: Int = 4
        val LOWTOM: Int = 5
        val HIHATOPEN: Int = 6
        val HIHATCLOSED: Int = 7

        // initial pan position for each drum sample
        val PAN_BASSDRUM: Float = 0f         // Dead Center
        val PAN_SNAREDRUM: Float = 0.25f     // A little Right
        val PAN_CRASHCYMBAL: Float = -0.75f  // Mostly Left
        val PAN_RIDECYMBAL: Float = 1.0f     // Hard Right
        val PAN_MIDTOM: Float = -0.75f       // Mostly Left
        val PAN_LOWTOM: Float = 0.75f        // Mostly Right
        val PAN_HIHATOPEN: Float = -1.0f     // Hard Left
        val PAN_HIHATCLOSED: Float = -1.0f   // Hard Left

        // Logging Tag
        val TAG: String = "DrumPlayer"
    }

    fun setupAudioStream() {
        setupAudioStreamNative(NUM_PLAY_CHANNELS)
    }

    fun startAudioStream() {
        startAudioStreamNative();
    }

    fun teardownAudioStream() {
        teardownAudioStreamNative()
    }

    // asset-based samples
    fun loadWavAssets(assetMgr: AssetManager): Boolean {
        var allAssetsCorrect = true
        allAssetsCorrect = loadWavAsset(assetMgr, "KickDrum.wav", BASSDRUM, PAN_BASSDRUM) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "SnareDrum.wav", SNAREDRUM, PAN_SNAREDRUM) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "CrashCymbal.wav", CRASHCYMBAL, PAN_CRASHCYMBAL) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "RideCymbal.wav", RIDECYMBAL, PAN_RIDECYMBAL) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "MidTom.wav", MIDTOM, PAN_MIDTOM) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "LowTom.wav", LOWTOM, PAN_LOWTOM) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "HiHat_Open.wav", HIHATOPEN, PAN_HIHATOPEN) && allAssetsCorrect
        allAssetsCorrect = loadWavAsset(assetMgr, "HiHat_Closed.wav", HIHATCLOSED, PAN_HIHATCLOSED) && allAssetsCorrect

        return allAssetsCorrect
    }

    fun unloadWavAssets() {
        unloadWavAssetsNative()
    }

    fun loadWavAsset(assetMgr: AssetManager, assetName: String, index: Int, pan: Float) : Boolean {
        var returnVal = false
        try {
            val assetFD = assetMgr.openFd(assetName)
            val dataStream = assetFD.createInputStream();
            var dataLen = assetFD.getLength().toInt()
            var dataBytes: ByteArray = ByteArray(dataLen)
            dataStream.read(dataBytes, 0, dataLen)
            returnVal = loadWavAssetNative(dataBytes, index, pan, NUM_SAMPLE_CHANNELS)
            assetFD.close()
        } catch (ex: IOException) {
            Log.i(TAG, "IOException" + ex)
        }

        return returnVal
    }

    external fun setupAudioStreamNative(numChannels: Int)
    external fun startAudioStreamNative();
    external fun teardownAudioStreamNative()

    external fun loadWavAssetNative(
            wavBytes: ByteArray, index: Int, pan: Float, channels: Int) : Boolean
    external fun unloadWavAssetsNative()

    external fun trigger(drumIndex: Int)

    external fun setPan(index: Int, pan: Float)
    external fun getPan(index: Int): Float

    external fun setGain(index: Int, gain: Float)
    external fun getGain(index: Int): Float

    external fun getOutputReset() : Boolean
    external fun clearOutputReset()

    external fun restartStream()
}
