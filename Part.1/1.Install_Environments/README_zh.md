# 安装开发环境

[English](README.md) | [中文](README_zh.md)

## 1. 安装 ARM 工具链

前往 GNU Arm Embedded Toolchain [下载页面](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)下载最新版本的工具链。

macOS 用户可以使用 `brew` 来安装工具链。

```bash
brew install gcc-arm-embedded
```

## 2. 安装 STM32CubeMX

前往 [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) 下载页面下载最新版本的工具。

## 3. 安装 OpenOCD

前往 [OpenOCD](http://openocd.org/) 下载页面下载最新版本的工具。
记得将 OpenOCD 的路径添加到环境变量中。
在 macOS 中你可以使用 `brew` 来安装 OpenOCD。

```bash
brew install openocd
```

## 4. 安装 cmake

前往 [cmake](https://cmake.org/) 下载页面下载最新版本的工具。

## 5. 安装 LLVM(For clang-format, Windows only)

前往 [LLVM](https://releases.llvm.org/download.html) 下载页面下载最新版本的工具。

## 6. 安装 ninja(For cmake, Windows only)

前往 [ninja](https://ninja-build.org/) 下载页面下载最新版本的工具。

## 7. 安装 Clion

前往 [Clion](https://www.jetbrains.com/clion/) 下载页面下载最新版本的工具。
你应该使用你的教育邮箱来申请学生许可。

## 8. 配置 Clion

前往 Settings -> Build, Execution, Deployment -> Embedded Development, 设置工具链、OpenOCD 和 STM32CubeMX 的路径。
(仅限 Windows) 前往 Settings -> Build, Execution, Deployment -> Toolchains, 设置 cmake 和 ninja 的路径。
