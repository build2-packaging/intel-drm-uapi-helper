# intel-drm-uapi-helper - <SUMMARY>

This is a `build2` package repository for [`intel-drm-uapi-helper`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`intel-drm-uapi-helper` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `intel-drm-uapi-helper` uses the standard `bdep`-based workflow.
For example:

```
git clone .../intel-drm-uapi-helper.git
cd intel-drm-uapi-helper

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
