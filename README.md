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

## Install dependencies

On Unix, before run `vcpkg install`, check you have installed `libgl-dev`;

`./thirdparty/vcpkg/vcpkg --x-manifest-root=. install [--triplet {triplet}]`

You can use a specific triplet for package installation, e.g. `--triplet x64-windows` or `--triplet x64-linux`.

# Build

```mkdir build
cd build
cmake [-G "{your favourite compiler configuration}"] -DVCPKG_TARGET_TRIPLET=x64-linux ..
```