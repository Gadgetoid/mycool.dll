# mycool

My awesome DLL app!

A handy shared library for Windows CE handhelds, built with my awesome
toolchain, [grimace](https://github.com/grimace-sdk/grimace).

## API

| Export | Does |
| --- | --- |
| `BSQCORE_Version` | returns the version |
| `EvaluationStatus` | returns the status |
| `GetCEInformation` | reports the OS version |
| `ShowAboutBox` | shows the about box |
| `ShowAboutBoxEx` | shows the about box |

## Build

With grimace checked out alongside this repo:

```sh
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=../grimace/cmake/toolchain.cmake \
  -DGRIMACE_ARCH=sh3 -DGRIMACE_CE_VERSION=2
cmake --build build                    # build/mycool.dll
cmake --build build --target packages  # build/packages/*.cab, *.zip, *-setup.exe
```

| `GRIMACE_ARCH` | `GRIMACE_CE_VERSION` |
| --- | --- |
| `sh3` | `2` |
| `mips` | `2` |
| `arm` | `3` |

CI builds all three on every push; see `.github/workflows/build.yml`.

## Install

Each architecture builds three ways:

- `*.cab` - wceload installs it on CE 2.0 and later.
- `*-setup.exe` - a self-installer that also runs on CE 1.0. Run it on the
  device (`/q` to skip the prompt); run it again to remove.
- `*.zip` - the raw files.

`mycool.dll` installs to `\Windows`.
