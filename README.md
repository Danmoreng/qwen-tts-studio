# Qwen-TTS Studio

⚠️ **ALPHA STATUS & DISCLAIMER** ⚠️

This project is a **super unfinished, quick weekend project**. It is currently in **alpha** stage and should be considered experimental software. 

**Please be aware:**
- **Not User-Friendly:** This is currently hard for other people to get running.
- **Hardcoded Paths:** There are several hardcoded paths in the source code that will need to be manually adjusted for your environment.
- **Manual Model Setup:** You cannot just run the app and have it work. You must manually use the Python conversion scripts in the `external/qwen3-tts-cpp` submodule to convert the HuggingFace models (0.6B) into the required GGUF format.
- **Broken 1.7B Support:** The 1.7B model version **does not work yet** and is currently unsupported. Only the 0.6B model is partially functional.
- **Missing Features:** Many UI elements (like style instructions and hardware acceleration selection) are currently placeholders or have been hidden because they are not yet backed by a stable implementation.

---

Qwen-TTS Studio is a native, minimalist desktop application for Windows and Linux that provides local Text-to-Speech (TTS) synthesis. It leverages the **Qwen3-TTS** (based on the CosyVoice architecture) model with a C++ backend.

## 🚀 Current State

- **Local Synthesis:** Functional for the 0.6B model if correctly configured.
- **Modern UI:** Built with Compose Multiplatform (Material 3).
- **Voice Cloning:** Basic support for Zero-Shot Cloning using the 0.6B model.
- **Backend:** C++ Inference Engine using [qwen3-tts.cpp](https://github.com/Danmoreng/qwen3-tts.cpp/tree/feat/cuda-support).

## 🛠️ Technology Stack

- **Frontend:** [Compose Multiplatform](https://www.jetbrains.com/lp/compose-multiplatform/) (Kotlin)
- **Backend:** C++ Inference Engine using [qwen3-tts.cpp](https://github.com/Danmoreng/qwen3-tts.cpp/tree/feat/cuda-support).
- **Interoperability:** JNA to interface with the native shared library.

## 🏗️ Getting Started (For Developers Only)

Refer to the [Development Plan](docs/DEVELOPMENT_PLAN.md) for the roadmap, but expect to spend time debugging the build environment and model paths.

### Running from source

1. Clone the repository and initialize submodules:
   ```bash
   git clone --recursive https://github.com/Danmoreng/qwen-tts-studio.git
   ```
2. **Convert Models:** Follow instructions in `external/qwen3-tts-cpp` to use the Python scripts for generating `.gguf` files for the 0.6B model.
3. **Fix Paths:** Search the codebase for hardcoded paths (e.g., in `SettingsViewModel.kt`) and update them to point to your model directory.
4. **Build Native:**
   ```powershell
   .\scripts\build-native.ps1
   ```
5. **Run App:**
   ```powershell
   .\gradlew.bat :composeApp:run
   ```

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
