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

#include "common/SystemUtils.h"

#include "common/Assert.h"
#include "common/Log.h"

#if defined(DAWN_PLATFORM_WINDOWS)
#    include <Windows.h>
#    include <vector>
#elif defined(DAWN_PLATFORM_LINUX)
#    include <dlfcn.h>
#    include <limits.h>
#    include <unistd.h>
#    include <cstdlib>
#elif defined(DAWN_PLATFORM_MACOS) || defined(DAWN_PLATFORM_IOS)
#    include <dlfcn.h>
#    include <mach-o/dyld.h>
#    include <vector>
#endif

#include <array>

#if defined(DAWN_PLATFORM_WINDOWS)
const char* GetPathSeparator() {
    return "\\";
}

std::pair<std::string, bool> GetEnvironmentVar(const char* variableName) {
    // First pass a size of 0 to get the size of variable value.
    DWORD sizeWithNullTerminator = GetEnvironmentVariableA(variableName, nullptr, 0);
    if (sizeWithNullTerminator == 0) {
        DWORD err = GetLastError();
        if (err != ERROR_ENVVAR_NOT_FOUND) {
            dawn::WarningLog() << "GetEnvironmentVariableA failed with code " << err;
        }
        return std::make_pair(std::string(), false);
    }

    // Then get variable value with its actual size.
    std::vector<char> buffer(sizeWithNullTerminator);
    DWORD sizeStored =
        GetEnvironmentVariableA(variableName, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (sizeStored + 1 != sizeWithNullTerminator) {
        DWORD err = GetLastError();
        if (err) {
            dawn::WarningLog() << "GetEnvironmentVariableA failed with code " << err;
        }
        return std::make_pair(std::string(), false);
    }
    return std::make_pair(std::string(buffer.data(), sizeStored), true);
}

bool SetEnvironmentVar(const char* variableName, const char* value) {
    return SetEnvironmentVariableA(variableName, value) == TRUE;
}
#elif defined(DAWN_PLATFORM_POSIX)
const char* GetPathSeparator() {
    return "/";
}

std::pair<std::string, bool> GetEnvironmentVar(const char* variableName) {
    char* value = getenv(variableName);
    return value == nullptr ? std::make_pair(std::string(), false)
                            : std::make_pair(std::string(value), true);
}

bool SetEnvironmentVar(const char* variableName, const char* value) {
    if (value == nullptr) {
        return unsetenv(variableName) == 0;
    }
    return setenv(variableName, value, 1) == 0;
}
#else
#    error "Implement Get/SetEnvironmentVar for your platform."
#endif

#if defined(DAWN_PLATFORM_WINDOWS)
std::string GetExecutablePath() {
    std::array<char, MAX_PATH> executableFileBuf;
    DWORD executablePathLen = GetModuleFileNameA(nullptr, executableFileBuf.data(),
                                                 static_cast<DWORD>(executableFileBuf.size()));
    return executablePathLen > 0 ? std::string(executableFileBuf.data()) : "";
}
#elif defined(DAWN_PLATFORM_LINUX)
std::string GetExecutablePath() {
    std::array<char, PATH_MAX> path;
    ssize_t result = readlink("/proc/self/exe", path.data(), PATH_MAX - 1);
    if (result < 0 || static_cast<size_t>(result) >= PATH_MAX - 1) {
        return "";
    }

    path[result] = '\0';
    return path.data();
}
#elif defined(DAWN_PLATFORM_MACOS) || defined(DAWN_PLATFORM_IOS)
std::string GetExecutablePath() {
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);

    std::vector<char> buffer(size + 1);
    if (_NSGetExecutablePath(buffer.data(), &size) != 0) {
        return "";
    }

    buffer[size] = '\0';
    return buffer.data();
}
#elif defined(DAWN_PLATFORM_FUCHSIA)
std::string GetExecutablePath() {
    // TODO: Implement on Fuchsia
    return "";
}
#elif defined(DAWN_PLATFORM_EMSCRIPTEN)
std::string GetExecutablePath() {
    UNREACHABLE();
    return "";
}
#else
#    error "Implement GetExecutablePath for your platform."
#endif

std::string GetExecutableDirectory() {
    std::string exePath = GetExecutablePath();
    size_t lastPathSepLoc = exePath.find_last_of(GetPathSeparator());
    return lastPathSepLoc != std::string::npos ? exePath.substr(0, lastPathSepLoc + 1) : "";
}

#if defined(DAWN_PLATFORM_LINUX) || defined(DAWN_PLATFORM_MACOS) || defined(DAWN_PLATFORM_IOS)
std::string GetModulePath() {
    static int placeholderSymbol = 0;
    Dl_info dlInfo;
    if (dladdr(&placeholderSymbol, &dlInfo) == 0) {
        return "";
    }

    std::array<char, PATH_MAX> absolutePath;
    if (realpath(dlInfo.dli_fname, absolutePath.data()) == NULL) {
        return "";
    }
    return absolutePath.data();
}
#elif defined(DAWN_PLATFORM_WINDOWS)
std::string GetModulePath() {
    UNREACHABLE();
    return "";
}
#elif defined(DAWN_PLATFORM_FUCHSIA)
std::string GetModulePath() {
    UNREACHABLE();
    return "";
}
#elif defined(DAWN_PLATFORM_EMSCRIPTEN)
std::string GetModulePath() {
    UNREACHABLE();
    return "";
}
#else
#    error "Implement GetModulePath for your platform."
#endif

std::string GetModuleDirectory() {
    std::string modPath = GetModulePath();
    size_t lastPathSepLoc = modPath.find_last_of(GetPathSeparator());
    return lastPathSepLoc != std::string::npos ? modPath.substr(0, lastPathSepLoc + 1) : "";
}

// ScopedEnvironmentVar

ScopedEnvironmentVar::ScopedEnvironmentVar(const char* variableName, const char* value)
    : mName(variableName),
      mOriginalValue(GetEnvironmentVar(variableName)),
      mIsSet(SetEnvironmentVar(variableName, value)) {
}

ScopedEnvironmentVar::~ScopedEnvironmentVar() {
    if (mIsSet) {
        bool success = SetEnvironmentVar(
            mName.c_str(), mOriginalValue.second ? mOriginalValue.first.c_str() : nullptr);
        // If we set the environment variable in the constructor, we should never fail restoring it.
        ASSERT(success);
    }
}

bool ScopedEnvironmentVar::Set(const char* variableName, const char* value) {
    ASSERT(!mIsSet);
    mName = variableName;
    mOriginalValue = GetEnvironmentVar(variableName);
    mIsSet = SetEnvironmentVar(variableName, value);
    return mIsSet;
}
