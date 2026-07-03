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

The helper script can rebuild native libraries and then launch the app in one step:

```powershell
.\scripts\run-compose.ps1 -BuildNative
.\scripts\run-compose.ps1 -Cuda -BuildNative
```

Use `-BuildNative` after updating `external/qwen3-tts-cpp` or changing JNI-facing native code. Otherwise Kotlin may call a JNI symbol that is not present in the previously copied `qwen3_tts.dll`.

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

The default CUDA package includes `ggml-cuda.dll` but does not bundle NVIDIA runtime DLLs such as `cublasLt64_13.dll`. The target machine must provide those DLLs through `CUDA_PATH`, `CUDAToolkit_ROOT`, or `PATH`.

**Create Offline CUDA Package:**
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\package-windows.ps1 -Cuda -BuildMsi -BundleCudaRuntime
```

This bundles the NVIDIA CUDA runtime DLLs into the app image. It is more portable, but the resulting ZIP/MSI is much larger.

The outputs will be available in `composeApp/build/compose/binaries/main/`.

GitHub releases publish both variants:

- `windows-cuda-system`: smaller ZIP/MSI with `ggml-cuda.dll`, requiring CUDA runtime DLLs from a local CUDA installation.
- `windows-cuda-bundled`: larger ZIP/MSI with NVIDIA CUDA runtime DLLs included.

### Linux

**Create Standalone App:**
```bash
chmod +x scripts/package-linux.sh
./scripts/package-linux.sh
```

The standalone app will be in `composeApp/build/compose/binaries/main/app/qwen-tts-studio`.

## Technical Details

### `scripts/build-native.ps1` (Windows)
The script resolves a JDK for JNI headers, loads the Visual Studio build environment, configures CMake from the `external/` directory, and builds the `qwen3_tts_shared` target.

### `scripts/package-windows.ps1` (Windows)
This script automates the entire process: it rebuilds the native backend, calls Gradle to create the app image, and bundles the native libraries and assets into a final package. CUDA runtime DLLs are only included when `-BundleCudaRuntime` is passed.

## Troubleshooting

- **Missing JNI Headers:** Ensure your `JAVA_HOME` environment variable points to a valid JDK 21+ or that `java.exe` is on your PATH.
- **CUDA Errors:** Ensure the `CUDA_PATH` environment variable is set so the build script can find the CUDA toolkit.
- **`UnsatisfiedLinkError` for a new native method:** Rebuild the native backend and restart the app. On Windows, run `.\scripts\run-compose.ps1 -Cuda -BuildNative` or `pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1 -Cuda`. The JVM cannot reload an already-loaded DLL inside the same app process.
- **Submodules Not Found:** If `external/qwen3-tts-cpp` is empty, run `git submodule update --init --recursive`.
