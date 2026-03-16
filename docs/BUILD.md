# Build Guide

This document describes how to build and package Qwen-TTS Studio from source for Windows and Linux.

## Requirements

### Windows
- **Visual Studio 2022 Build Tools** with the "Desktop development with C++" workload.
- **CMake 3.14+**.
- **Java 21+ JDK/JBR** (required for JNI development files and packaging with `jpackage`).
- **NVIDIA CUDA Toolkit** (only if building with CUDA support).
- **Ninja** (optional but recommended for faster builds).

### Linux
- **GCC 9+ or Clang 10+**.
- **CMake 3.14+**.
- **Java 21+ JDK/JBR**.
- **NVIDIA CUDA Toolkit** (only if building with CUDA support).

## Build Native Backend

The native C++ backend must be built first.

### Windows

**Build for CPU:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1
```

**Build with CUDA Support:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1 -Cuda
```

The script automatically detects your Visual Studio environment and Ninja if installed. It will copy the resulting DLLs to the root directory for use by the application.

### Linux

**Build for CPU:**
```bash
chmod +x scripts/build-native.sh
./scripts/build-native.sh
```

The script will build the native backend and copy the resulting `.so` library to the root directory.

## Run from Source

Once the native backend is built, you can run the application directly from source:

### Windows
```powershell
.\gradlew.bat :composeApp:run
```

### Linux
```bash
./gradlew :composeApp:run
```

## Packaging

You can package the application into a standalone executable or an installer.

### Windows

**Create Portable App:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\package-windows.ps1
```

**Create MSI Installer:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\package-windows.ps1 -BuildMsi
```

**Create App with CUDA Support:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\package-windows.ps1 -Cuda
```

The outputs will be available in `composeApp/build/compose/binaries/main/`.

### Linux

**Create Standalone App:**
```bash
chmod +x scripts/package-linux.sh
./scripts/package-linux.sh
```

The standalone app will be in `composeApp/build/compose/binaries/main/app/qwen-tts-studio`.

## Technical Details

### `scripts/build-native.ps1` (Windows)
The script resolves a JDK for JNI headers, loads the Visual Studio build environment, configures CMake from the `external/` directory, and builds the `qwen3_tts_shared` target. For CUDA builds, it also bundles the necessary CUDA runtime DLLs.

### `scripts/package-windows.ps1` (Windows)
This script automates the entire process: it rebuilds the native backend, calls Gradle to create the app image, and bundles the native libraries and assets into a final package.

## Troubleshooting

- **Missing JNI Headers:** Ensure your `JAVA_HOME` environment variable points to a valid JDK 21+ or that `java.exe` is on your PATH.
- **CUDA Errors:** Ensure the `CUDA_PATH` environment variable is set so the build script can find the CUDA toolkit.
- **Submodules Not Found:** If `external/qwen3-tts-cpp` is empty, run `git submodule update --init --recursive`.
