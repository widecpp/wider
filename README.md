# wider

# Build Requirements

* CMake
* vcpkg (instaled as submodule in thridpart/vcpkg)

## Configure vcpkg

On Windows:
`thirdparty\vcpkg\bootstrap-vcpkg.bat`
On Unix:
`./thirdparty/vcpkg/bootstrap-vcpkg.sh`

## Install next packages

* sdl2

# Build

```mkdir build
cd build
cmake -G [your favourite compiler] -DCMAKE_TOOLCHAIN_FILE=..\thirdparty\vcpkg\scripts\buildsystems\vcpkg.cmake ..
```