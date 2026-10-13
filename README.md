# intel-drm-uapi-helper - Linux DRM uAPI C headers with the Intel PRELIM i915 extensions

This is a `build2` package repository for
[`drm-uapi-helper`](https://github.com/intel-gpu/drm-uapi-helper),
the Linux DRM and i915 kernel uAPI headers of the Intel GPGPU (DGPU)
releases, including the "PRELIM" i915 uAPI extensions.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libdrm-uapi-helper` in your `build2`-based project, then instead see the
accompanying [`PACKAGE-README.md`](libdrm-uapi-helper/PACKAGE-README.md) file.

The development setup for `intel-drm-uapi-helper` uses the standard
`bdep`-based workflow. The headers are only supported on Linux. For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/intel-drm-uapi-helper.git
cd intel-drm-uapi-helper

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
