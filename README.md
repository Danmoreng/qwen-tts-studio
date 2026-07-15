# Qwen-TTS Studio

Qwen-TTS Studio is a modern desktop application for high-quality, local text-to-speech generation. It leverages a high-performance C++ backend (`qwen3-tts.cpp`) to provide fast inference without the need for Python or a cloud connection.

![Qwen-TTS Studio Screenshot](docs/images/studio-screenshot.png)

## Features

- **Local Inference:** All processing happens on your machine. No data leaves your computer.
- **High Performance:** Powered by a native C++ engine with support for CPU and NVIDIA CUDA acceleration.
- **Voice Cloning:** Create custom voice presets from a short reference audio clip, with reusable speaker embeddings and optional full ICL voice prompts (supported by Base models).
- **Voice Lab:** Morph or average compatible speaker embeddings, inspect exact mix geometry, preview the result, or apply an experimental user-defined reference direction to a base voice.
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

After updating `external/qwen3-tts-cpp` or any JNI/native API surface, rebuild the native backend before running:

```powershell
.\scripts\run-compose.ps1 -Cuda -BuildNative
```

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
- **Clone Mode:** For custom voice presets, choose **Embedding** for the lightweight speaker-embedding path or **ICL** for the full prompt path when a reference transcript was saved.
- **Instruction:** (If supported) Enter style instructions like "Whispering" or "Excited".
- **Generate:** Click to synthesize and play the audio.

### Voices
Manage your voice presets.
- **Extract:** Upload or record a short WAV file (3-10 seconds) to extract reusable speaker embeddings.
- **ICL Prompt:** Optionally enter the transcript of the reference audio to save a full ICL voice prompt. ICL prompts include the speaker embedding, reference text tokens, and reference speech codes for reuse.
- **Save:** Give your custom voice a name to use it in the Studio tab. Missing embedding or ICL prompt dimensions can be generated later from the saved preset.

### Voice Lab
Create derived presets from embeddings that were extracted with the same Qwen3-TTS Base checkpoint and share the same model dimension.
- **Morph:** Interpolate between two complete speaker embeddings.
- **Average:** Build an equal-weight mean from two or more embeddings, optionally rescaled by norm. Averaging multiple recordings of the same speaker is an experimental use case, not a validated robustness guarantee.
- **Reference direction (experimental):** Apply `base + strength × (toward − from)`. Prefer paired reference recordings of the same speaker, microphone, and phrase in two different styles.
- **Norm preservation:** Optionally rescale the result to the weighted source/base L2 norm. This is a stability heuristic, not a guarantee of natural speech.
- **Embedding geometry:** For a two-voice morph, inspect the exact local A-to-B path, current result, vector distance/cosine diagnostics, and grouped latent-coordinate differences. These plots are embedding-space geometry, not frequency bands or a perceptual similarity score.
- **Preview before saving:** Enter a sentence and language to synthesize the current recipe through the selected Base model. The temporary embedding is deleted after generation; the resulting audio is played automatically and can be stopped or replayed.

An embedding is a learned 1024- or 2048-value latent vector, not a waveform, spectrum, or 2D frequency curve. Its coordinate indices do not correspond to Hertz, time, pitch, gender, accent, or emotion. Direction percentages scale the raw distance between the selected references; they are not quality or out-of-distribution scores, and even small shifts can produce artifacts. Compare results by ear.

The app currently verifies only that dimensions match; it does not store or verify the source checkpoint. Equal dimensions are necessary but not sufficient for compatibility. Speaker embeddings can contain identity-like biometric information: use recordings with consent. Derived voices are not automatically anonymous or free of source-voice rights.

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
