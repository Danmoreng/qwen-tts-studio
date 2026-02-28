# Specification & Development Plan: Qwen-TTS Studio

## 1. Project Overview

**Name:** Qwen-TTS Studio
**Description:** A native, minimalist desktop application (Windows & Linux) for local speech synthesis (Text-to-Speech) based on the Qwen3-TTS/CosyVoice model. The app utilizes an efficient C++ backend for inference and provides a modern, hardware-accelerated UI.
**Target Platforms:** Windows (.exe/.msi) and Linux (.deb/.rpm)
**Core Philosophy:** Local processing (Privacy-first), ultra-low latency, modern "Pro-Tool" UI (Dark Mode), and ease of use.

## 2. Technology Stack

*   **UI Framework:** Compose Multiplatform (CMP) by JetBrains.
*   **Programming Language (Frontend):** Kotlin.
*   **Architecture:** Kotlin Multiplatform (KMP) focused on JVM Desktop.
*   **State Management:** Kotlin Coroutines & StateFlow (MVI/MVVM Pattern).
*   **Backend / AI Inference:** Local C++ backend based on [qwen3-tts.cpp](https://github.com/Danmoreng/qwen3-tts.cpp/tree/feat/cuda-support) (a fork of predict-woo/qwen3-tts.cpp using ggml).
*   **Bridge (Kotlin <-> C++):** JNA (Java Native Access) or Project Panama (FFI) to call the engine's shared library (.dll/.so) asynchronously.
*   **Audio Playback:** JVM Standard Audio (javax.sound.sampled) or dedicated KMP Audio Library.

## 3. Core Features (MVP - Minimum Viable Product)

### 3.1. Speech Synthesis (Studio View)
*   **Text Input:** Large text field (max. 5000 characters).
*   **Voice Selection:** Dropdown to select system and cloned voices.
*   **Emotion Control:** Chips ("Neutral", "Happy", "Whisper", "Dynamic") that set internal prompt prefixes for the Qwen3 model.
*   **Audio Player:** Playback of generated audio including visual waveform (simulated or real) and download/export function (.wav).

### 3.2. Voice Cloning (Voices View)
*   **Zero-Shot Cloning:** Upload functionality for short audio samples (3-10 seconds, .wav).
*   **Voice Management:** List of cloned voices with a delete function.
*   **Note:** Voices are stored locally as metadata (path to sample & name) in a simple JSON or SQLite/Room database.

### 3.3. Setup & Monitoring (Settings View)
*   **Model Path:** Configuration of the file path to local Qwen3 model weights (.gguf or .bin).
*   **Hardware Acceleration:** Dropdown (CPU, CUDA, Vulkan).
*   **Live Monitoring:** Display of RAM usage and CPU/GPU status in the app header.

### 3.4. UI/UX Features
*   System-native Dark Mode & Light Mode support.
*   Navigation Rail (sidebar) for quick switching between views.
*   Modern Material 3 design without classic OS window frames (optional: Undecorated Window with Custom Titlebar).

## 4. Development Roadmap (Step-by-Step Plan)

This plan builds the app iteratively. Each step results in a runnable intermediate state.

### Phase 1: Project Setup & Infrastructure
- [ ] Generate the KMP Desktop project via JetBrains Wizard.
- [ ] Configure `build.gradle.kts` for Compose Desktop.
- [ ] Set up the entry point (`main.kt`) including window size, title, and icon.
- [ ] Set up the basic theme structure (Colors, Typography for Dark/Light Mode).

### Phase 2: UI Framework & Navigation (Mockup -> Compose)
- [ ] Build the Navigation Rail (sidebar) and the main layout container.
- [ ] Implement the header including the simulated hardware monitor.
- [ ] Create basic routing/navigation state (switching between Studio, Voices, Setup).

### Phase 3: Detailed UI Implementation (Screens)
- [ ] **Studio Screen:** Text field, Voice dropdown, Emotion chips, and the "Read Aloud" button.
- [ ] **Player Component:** Build the audio bar with animated Canvas waveform.
- [ ] **Voices Screen:** Grid layout for existing voices and the "Clone New Voice" card including OS file picker (AWT FileDialog).
- [ ] **Setup Screen:** Input fields for model paths.

### Phase 4: State Management & Logic Layer
- [ ] Create ViewModels/Controllers for the screens (separation of UI and logic).
- [ ] Implement local data storage (Preferences/JSON) for settings and saved voices.
- [ ] Connect UI actions (e.g., button clicks) to ViewModels (initially with simulated delays/mock data).

### Phase 5: The C++ Bridge (Kotlin Native Interop)
- [ ] Define the C++ interface (functions provided by the .dll/.so, e.g., `generate_audio(text, emotion, voice_sample_path)`).
- [ ] Set up JNA (or FFI) in Kotlin to call the native functions.
- [ ] Implement an asynchronous wrapper (suspend functions) to prevent UI freezing during generation.
- [ ] Integrate actual hardware monitoring (reading RAM/CPU via JVM APIs).

### Phase 6: Audio Processing & Polish
- [ ] Implement native audio playback to play the byte stream (PCM/WAV) returned by the C++ backend.
- [ ] Export function: Save the byte stream as a .wav file on disk.
- [ ] Final bug fixing, optimization of UI transitions and animations.

### Phase 7: Packaging & Distribution
- [ ] Configure ProGuard/R8 for code minimization (optional).
- [ ] Execute `packageDistributionForCurrentOS` task for Windows (.msi).
- [ ] Execute the task for Linux (.deb).
