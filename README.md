# wider

Our goals is to make fast, extensible and cross-platform IDE.
No garbage collectors, no GUI freaze or lags.

# Build Requirements

* CMake
* vcpkg (instaled as submodule in thridpart/vcpkg)

## Configure vcpkg

On Windows:
    `thirdparty\vcpkg\bootstrap-vcpkg.bat`

On Unix:
    `./thirdparty/vcpkg/bootstrap-vcpkg.sh`

## Install packages

`./thirdparty/vcpkg/vcpkg --x-manifest-root=. install`

# Build

```mkdir build
cd build
cmake -G [your favourite compiler] -DCMAKE_TOOLCHAIN_FILE=..\thirdparty\vcpkg\scripts\buildsystems\vcpkg.cmake ..
```