# Qwen-TTS Studio

Qwen-TTS Studio is a native, minimalist desktop application for Windows and Linux that provides local, high-quality Text-to-Speech (TTS) synthesis. It leverages the powerful **Qwen3-TTS** (based on the CosyVoice architecture) model with an efficient C++ backend to ensure privacy-first, low-latency performance.

## 🚀 Features

- **Local Synthesis:** All processing happens on your machine. No data leaves your computer.
- **Ultra-Low Latency:** Optimized C++ inference engine for near-instant speech generation.
- **Modern UI:** Built with Compose Multiplatform, featuring a sleek Material 3 design with full Dark Mode support.
- **Voice Cloning:** Clone voices with just a 3-10 second audio sample (Zero-Shot Cloning).
- **Emotion Control:** Direct control over speech emotions (e.g., Happy, Whisper, Dynamic) via prompt-based instructions.
- **Hardware Monitoring:** Real-time tracking of RAM and CPU/GPU usage within the app.

## 🛠️ Technology Stack

- **Frontend:** [Compose Multiplatform](https://www.jetbrains.com/lp/compose-multiplatform/) (Kotlin)
- **Backend:** C++ Inference Engine using [qwen3-tts.cpp](https://github.com/Danmoreng/qwen3-tts.cpp/tree/feat/cuda-support) (ggml-based with CUDA support).
- **Interoperability:** JNA / Project Panama (FFI) to interface with the native shared library.

## 📋 Requirements

- **JDK 17 or newer**
- **Windows** (10/11) or **Linux** (Ubuntu/Debian preferred)
- **Hardware:** Modern CPU/GPU for efficient inference.

## 🏗️ Getting Started

Currently, the project is in the initial development phase. Refer to the [Development Plan](docs/DEVELOPMENT_PLAN.md) for the detailed roadmap.

### Running from source

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/qwen-tts-studio.git
   ```
2. Open in **IntelliJ IDEA**.
3. Run the Gradle task:
   ```bash
   ./gradlew run
   ```

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
