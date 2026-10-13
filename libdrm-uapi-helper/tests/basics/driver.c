#include <drm-uapi/drm.h>
#include <drm-uapi/i915_drm.h>
#include <drm-uapi/i915_drm_prelim.h>

#include <i915-shared-headers/iaf_netlink.h>
#include <i915-shared-headers/intel_hwconfig_types.h>

#include <errno.h>
#include <sys/ioctl.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* The i915 uAPI on top of the core DRM uAPI.
   */
  {
    assert (DRM_IOCTL_BASE == 'd');
    assert (_IOC_TYPE (DRM_IOCTL_I915_GETPARAM) == DRM_IOCTL_BASE);
    assert (_IOC_NR (DRM_IOCTL_I915_GETPARAM) ==
            DRM_COMMAND_BASE + DRM_I915_GETPARAM);
    assert (_IOC_SIZE (DRM_IOCTL_I915_GETPARAM) ==
            sizeof (drm_i915_getparam_t));
    assert (sizeof (struct drm_i915_query_item) == 24);
  }

  /* The i915 PRELIM uAPI extensions.
   */
  {
    assert (PRELIM_I915_PARAM_HAS_VM_BIND == ((1 << 16) | 6));
    assert (_IOC_NR (PRELIM_DRM_IOCTL_I915_GEM_VM_BIND) ==
            DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_BIND);
  }

  /* The shared i915 headers.
   */
  {
    assert (INTEL_HWCONFIG_MAX_SLICES_SUPPORTED == 1);
    assert (IAF_CMD_OP_DEVICE_ENUM == 1);
  }

  /* Issue an i915 request on an invalid file descriptor.
   */
  {
    int v = 0;
    drm_i915_getparam_t gp = {.param = I915_PARAM_CHIPSET_ID, .value = &v};

    assert (ioctl (-1, DRM_IOCTL_I915_GETPARAM, &gp) == -1 && errno == EBADF);
  }

  return 0;
}
