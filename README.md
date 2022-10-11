# About

Fresh OpenGL template (bare minimum) project ready for development on windows/unix.

This project inlude:

* `glfw`
* `glew`
* `glm`

Requirements:

* `CMake` on all systems
* `TDM-GCC` on windows (see in compilers folder)
* or `MSVC` (not tested, may require additional changes!)
* Arch-based systems: `base-devel` packages
* Debian-based systems: `build-essential` packages
* Text editor, preferably `VSCode` with cmake extension for seamless work

Installation:

* Clone the repository
* Use cmake extension in vscode or cmake gui
* Select toolkit
* Build/Run the project

Known issues:

* If the build fails, `mingw32-make.exe` on windows has to be copied at the same location and be renamed to `make.exe`.
