# Qwen-TTS Studio Development Plan

## Project Goal

Desktop-first local TTS workflow with a modern UI and native C++ inference backend.

## Current Status

### Completed

- Desktop app UI with three areas:
  - `Studio` (generation)
  - `Voices` (voice presets from reference audio)
  - `Setup` (model configuration)
- Native bridge integration using JNI (`qwen3_tts.dll`).
- Submodule backend now tracks `qwen3-tts.cpp` after the architecture refactor, with:
  - Model-name aware loading
  - Named speaker API
  - Instruction + speaker plumbing in JNI/C/KMP layers
- Capability-driven UI behavior:
  - App detects model capabilities from loaded model metadata
  - Controls are shown/hidden based on detected capabilities
- Model-family behavior currently used in practice:
  - `Base` models: custom voice cloning flow enabled
  - `CustomVoice` models: named speaker flow enabled
- Studio behavior:
  - Model selector + language in first row
  - Speaker selector in second row for both model families
  - First named speaker auto-selected when model requires named speakers
- Voices behavior:
  - Voice extraction/presets enabled only when model supports cloning
  - Speaker presets remain embedding-dimension aware to avoid mismatched reuse

### In Progress / Known Issues

- Packaging and onboarding are still developer-oriented.
- Runtime and model validation UX can be improved (clearer diagnostics in Setup).
- Linux path and runtime validation is not yet fully documented/tested.

## Feature Matrix

| Feature | Base model family | CustomVoice model family |
|---|---|---|
| Text-to-speech generation | Yes | Yes |
| Custom voice cloning (reference WAV/embedding) | Yes | No |
| Instruction/style prompt | No (current Base models) | Yes (when capability is present) |
| Named speaker dropdown | No (current Base models) | Yes |

## Build and Run Workflow (Quick Start)

1. Build native backend:
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1
```

2. Run desktop app:
```powershell
.\gradlew.bat :composeApp:run
```

3. Configure in app:
- Setup `Model Directory`
- Pick `Model File Name` (the app derives behavior from model capabilities/family)

## Next Milestones

1. Improve Setup validation:
- Detect missing model files and show exact required filenames/dependencies per selected model.

2. Better generation diagnostics:
- Surface backend errors with actionable hints (bad model dir, missing tokenizer/vocoder, etc.).

3. Speaker UX polish (named-speaker models):
- Optional refresh button and loading state for speaker list retrieval.

4. Hybrid-capability model support:
- Support models that expose both named speakers/instruction and cloning in one checkpoint, with explicit UI precedence rules.

5. Distribution:
- Stable Windows package flow (CPU and CUDA variants).
