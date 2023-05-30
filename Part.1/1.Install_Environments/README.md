# Install Environments

[English](README.md) | [中文](README_zh.md)

## 1. Install Toolchain

Go to the GNU Arm Embedded Toolchain [download page](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) and download the latest version of the toolchain for your operating system.

## 2. Install STM32CubeMX

Go to the [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) download page and download the latest version of the tool for your operating system.

## 3. Install OpenOCD

Go to the [OpenOCD](http://openocd.org/) download page and download the latest version of the tool for your operating system.
Remember to add the path of OpenOCD to the environment variable.
In macOS you can use `brew` to install OpenOCD.

```bash
brew install openocd
```

## 4. Install cmake

Go to the [cmake](https://cmake.org/) download page and download the latest version of the tool for your operating system.

## 5. Install LLVM(For clang-format)

Go to the [LLVM](https://releases.llvm.org/download.html) download page and download the latest version of the tool for your operating system.

## 6. Install ninja(For cmake, Windows only)

Go to the [ninja](https://ninja-build.org/) download page and download the latest version of the tool for your operating system.

## 7. Install Clion

Go to the [Clion](https://www.jetbrains.com/clion/) download page and download the latest version of the tool for your operating system.
You should use your education email to apply for a student license.

## 8. Configure Clion

Go to Settings -> Build, Execution, Deployment -> Embedded Development, and set the path of the toolchain, OpenOCD and STM32CubeMX.
(For Windows only) Go to Settings -> Build, Execution, Deployment -> Toolchains, and set the path of cmake and ninja.
