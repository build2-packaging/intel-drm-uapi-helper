# libdrm-uapi-helper - Linux DRM uAPI C headers with the Intel PRELIM i915 extensions

This is a `build2` package for the
[`drm-uapi-helper`](https://github.com/intel-gpu/drm-uapi-helper) C library.
It provides a unified view of the Linux DRM and i915 kernel uAPI available in
the Intel GPGPU (DGPU) releases, in particular the "PRELIM" uAPI extensions
in `i915_drm_prelim.h`, as well as other i915 headers that are usually copied
to user space components.


## Usage

To start using `libdrm-uapi-helper` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libdrm-uapi-helper ^2.0.0-b.27
```

Then import the library in your `buildfile`:

```
import libs = libdrm-uapi-helper%lib{drm-uapi-helper}
```


## Importable targets

This package provides the following importable targets:

```
lib{drm-uapi-helper}
```

The headers, included with the upstream directory as the prefix
(`#include <drm-uapi/drm.h>`, `#include <drm-uapi/i915_drm.h>`, which also
includes `i915_drm_prelim.h`, `#include <i915-shared-headers/iaf_netlink.h>`,
and so on). The package version maps the upstream release candidates to
betas (`2.0.0-b.27` is `v2.0-rc27`).

The headers are only supported on Linux, where they include the kernel's
`<linux/types.h>` and `<asm/ioctl.h>` from the system (the Linux API headers
package, for example `linux-libc-dev` on Debian). The xe uAPI from the
separate upstream `xe` branch is not included. As in the kernel, `i810_drm.h`
and `msm_drm.h` use C++ keywords as member names and are C only.


## Configuration variables

This package provides no configuration variables.
