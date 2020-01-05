# PMM - The Package Manager Manager

![build-status](https://flat.badgen.net/github/status/AnotherFoxGuy/pmm/master?label=build%20status)
![release](https://flat.badgen.net/github/release/AnotherFoxGuy/pmm)
![last commit](https://flat.badgen.net/github/last-commit/AnotherFoxGuy/pmm)
![stars](https://flat.badgen.net/github/stars/AnotherFoxGuy/pmm)
![forks](https://flat.badgen.net/github/forks/AnotherFoxGuy/pmm)
![issues](https://flat.badgen.net/github/open-issues/AnotherFoxGuy/pmm)
![issues-pr](https://flat.badgen.net/github/open-prs/AnotherFoxGuy/pmm)
![contributors](https://flat.badgen.net/github/contributors/AnotherFoxGuy/pmm)

PMM is a module for CMake that manages... package managers.

## Wha- Why?

People hate installing new software. Especially when they already have a
perfectly working tool present. PMM uses the CMake scripting
language to manage external packaging tools. PMM will automatically
download, install, and control package managers from within your CMake
project.

## But This is Just *Another* Tool I have to Manage!

Never fear! PMM is the lowest-maintenance software you will ever use.

## How Do I Use PMM?

Using PMM is simple:

1. Download the [`pmm.cmake` file](https://anotherfoxguy.com/pmm/pmm.cmake), and place it at the top level of your repository
   (alongside your `CMakeLists.txt`).
2. In your `CMakeLists.txt`, add a line `include(pmm.cmake)`.
3. Call the `pmm()` CMake function.

That's it! The `pmm.cmake` file is just 23 significant lines. Take a look inside
if you doubt.

## Wait... It's Downloading a Bunch of Stuff!

Precisely! `pmm.cmake` is just a bootstrapper for the real PMM code, which
can be found in the `pmm/` directory in the repository. The content is
served over HTTPS from the `gh-pages` branch of the PMM repository, so it is all publicly visible.

## I Don't Want to Automatically Download and Run Code from the Internet

Great! I sympathize, but remember: If you run `apt`, `yum`, `pip`, or even
`conan`, you are automatically downloading and running code from the
internet. It's all about whose code you *trust*.

Even still, you can host the PMM code yourself: Download the `pmm/`
directory as you want it, and modify the `pmm.cmake` script to download
from your alternate location (eg, a corporate engineering intranet server).

## Will PMM Updates Silently Break my Build?

Nope. `pmm.cmake` will never automatically change the version of PMM that
it uses, and the files served will never be modified in-place: New versions
will be *added,* but old versions will remain unmodified.

PMM will notify you if a new version is available, but it won't be annoying
about it, and you can always disable this nagging by setting
`PMM_IGNORE_NEW_VERSION` before including `pmm.cmake`.

## How do I Change the PMM Version?

There are two ways:

1. Set `PMM_VERSION` before including the `pmm.cmake` script.
2. Modify the `PMM_VERSION_INIT` value at the top of `pmm.cmake`.

Prefer (1) for conditional/temporary version changes, and (2) for permanent
version changes.

## How do I Change the Download Location for PMM?

For permanent changes, set `PMM_URL` and/or `PMM_URL_BASE` in `pmm.cmake`.
For temporary changes, set `PMM_URL` before including `pmm.cmake`

# The `pmm()` Function

The only interface to PMM (after including `pmm.cmake`) is the `pmm()`
CMake function. Using it is very simple. At the time or writing, `pmm()`
only supports Conan and vcpkg, but other packaging solutions may be supported
in the future.

The `VERBOSE` and `DEBUG` options enable verbose and debug logging,
respectively. You may set `PMM_{DEBUG,VERBOSE}` before `include(pmm.cmake)` to
enable these options globally and see information about the PMM bootstrapping
process.

The `pmm()` signature:

```cmake
pmm(
    # Enable verbose logging
    [VERBOSE]
    # Enable debug logging (implies VERBOSE)
    [DEBUG]
    # Use Conan
    [CONAN]
    # Use vcpkg
    [VCPKG]
    # Use CMakeCM
    [CMakeCM]
)
```
See the documentation for the specific modules:
- [Conan](Conan.md)
- [vcpkg](VCPKG.md)
- [CMakeCM](CMakeCM.md)
- [CLI](CLI.md)



