# Conan

## Install conan 2 or later
For Windows:
```
winget conan
# or
winget upgrade conan
```

## Create profile if it does not exist

```
conan profile detect
```

Creates ~/.conan2/profiles/default
Will create a Release build profile.  Copy the file to create a debug profile named 'debug'. Inside the file change the build type from Release to Debug.

## Get dependencies with conan

```
conan install . -sbuild_type=Debug -of="conan/debug" --build=missing
```

# Configure with CMake

On Windows, use the 'Developer Command Prompt' command line:

```
mkdir build
cd build

cmake .. -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
# or on Linux
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../conan/debug/build/Debug/generators/conan_toolchain.cmake

cmake --build .
```

# Change to CMakePresets.json

On linux the path to the conan_toolchain.cmake was different in the CMakePresets.json.

Here is the original:

 "name": "conan-debug",
 "hidden": true,
 "cacheVariables": {
     "CMAKE_TOOLCHAIN_FILE": "${sourceDir}/conan/debug/build/generators/conan_toolchain.cmake"
 }

Change the one line (to add /Debug):
     "CMAKE_TOOLCHAIN_FILE": "${sourceDir}/conan/debug/build/Debug/generators/conan_toolchain.cmake"

Make sure it matches the CMakeUserPresets.json file (and both should match the actual path under conan directory).