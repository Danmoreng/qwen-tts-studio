# Qwen-TTS Studio

Qwen-TTS Studio is a modern desktop application for high-quality, local text-to-speech generation. It leverages a high-performance C++ backend (`qwen3-tts.cpp`) to provide fast inference without the need for Python or a cloud connection.

![Qwen-TTS Studio Screenshot](docs/images/studio-screenshot.png)

## Features

- **Local Inference:** All processing happens on your machine. No data leaves your computer.
- **High Performance:** Powered by a native C++ engine with support for CPU and NVIDIA CUDA acceleration.
- **Voice Cloning:** Create custom voice presets from a short reference audio clip (supported by Base models).
- **Instruction Control:** Use natural language prompts to control voice design, tone, emotion, and style (supported by 1.7B CustomVoice and VoiceDesign models).
- **Named Speakers:** Built-in support for models with predefined speaker profiles.
- **Adaptive UI:** The interface automatically adapts to the capabilities of the loaded model.
- **Cross-Platform:** Built with Compose Multiplatform, supporting Windows and Linux.

## Quick Start

### Download for Windows

Pre-built Windows releases are available on the
[GitHub Releases page](https://github.com/Danmoreng/qwen-tts-studio/releases).
You can download either an MSI installer or a portable ZIP package and run the
app without building it yourself.

The CUDA release variants include the native backend. Choose the smaller
`windows-cuda-system` package if you already have the NVIDIA CUDA runtime
installed, or the larger `windows-cuda-bundled` package for an offline package
that includes the required CUDA runtime DLLs.

### 1. Build Prerequisites

These are only required when building from source.

- **Windows:** Visual Studio 2022 Build Tools, CMake, and a Java 21+ JDK.
- **Linux:** GCC/Clang, CMake, and a Java 21+ JDK.
- **NVIDIA GPU (Optional):** CUDA Toolkit for hardware acceleration.

### 2. Build from Source

```bash
# Clone the repository with submodules
git clone --recursive https://github.com/Danmoreng/qwen-tts-studio.git
cd qwen-tts-studio

# Build the native backend (Windows)
pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1

# Build the native backend (Linux)
chmod +x scripts/build-native.sh
./scripts/build-native.sh

# Run the application
# Windows:
.\scripts\run-compose.ps1
# Linux:
./gradlew :composeApp:run
```

For detailed build instructions, including CUDA support and packaging, see [docs/BUILD.md](docs/BUILD.md).

### Windows Packaging

```powershell
# CUDA package that uses a locally installed CUDA runtime
.\scripts\package-windows.ps1 -Cuda -UseNinja

# Portable zip and MSI installer
.\scripts\package-windows.ps1 -Cuda -UseNinja -BuildMsi

# Offline CUDA package that bundles NVIDIA runtime DLLs (much larger)
.\scripts\package-windows.ps1 -Cuda -UseNinja -BuildMsi -BundleCudaRuntime
```

Tagged pushes matching `v*` and manual dispatches run `.github/workflows/windows-release.yml`, producing two Windows ZIP/MSI variants:

- `windows-cuda-system`: smaller package. Includes the CUDA backend, but expects NVIDIA CUDA runtime DLLs from a local CUDA installation. It falls back to CPU when CUDA is unavailable.
- `windows-cuda-bundled`: larger offline package. Includes NVIDIA CUDA runtime DLLs so CUDA works without a separate CUDA Toolkit installation.

### 3. Model Setup

Qwen-TTS Studio requires GGUF model files to operate.

1.  **Download Models:** On first launch, the Welcome setup can download GGUF models from [Serveurperso/Qwen3-TTS-GGUF](https://huggingface.co/Serveurperso/Qwen3-TTS-GGUF/tree/main). You can also use the same downloader later from the **Setup** tab.
2.  **Prepare Models Manually:** If you bring your own model files, place one `qwen-tokenizer-*` GGUF and one or more Serveurperso-style `qwen-talker-*` GGUF files in the model directory.
3.  **Configure App:**
    - Open Qwen-TTS Studio and go to the **Setup** tab.
    - Set your **Model Directory**.
    - Select your **Model File** from the list.

## Usage Guide

### Studio
The main generation interface.
- **Text:** Enter the text you want to synthesize.
- **Speaker:** Select a named speaker or a custom voice preset.
- **Instruction:** (If supported) Enter style instructions like "Whispering" or "Excited".
- **Generate:** Click to synthesize and play the audio.

### Voices
Manage your voice presets.
- **Extract:** Upload a short WAV file (3-10 seconds) to extract a voice embedding.
- **Save:** Give your custom voice a name to use it in the Studio tab.

### Setup
Configure application settings and models.
- **Model Path:** The folder where your GGUF models are stored.
- **Backend:** Monitor and configure backend settings (CPU/CUDA).

## Documentation

- [Build Guide](docs/BUILD.md) - Detailed compilation and packaging instructions.
- [Development Plan](docs/DEVELOPMENT_PLAN.md) - Project roadmap and implementation details.
- [Native Backend](https://github.com/Danmoreng/qwen3-tts.cpp) - Technical details about the high-performance C++ engine.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
