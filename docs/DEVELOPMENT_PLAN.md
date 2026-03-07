# Qwen-TTS Studio Development Plan

## Project goal

Desktop-first local TTS workflow with a modern UI and native C++ inference backend.

## Current implementation snapshot (March 2026)

### Completed

- Desktop app UI with three areas:
  - `Studio` (generation)
  - `Voices` (voice presets from reference audio)
  - `Setup` (model configuration)
- Native bridge integration using JNI (`qwen3_tts.dll`).
- Submodule backend upgraded to newer `qwen3-tts.cpp` branch with:
  - model-name aware loading
  - named speaker API
  - instruction + speaker plumbing in JNI/C/KMP layers
- Capability-driven UI behavior (no fixed size switch):
  - app detects model capabilities from loaded model metadata
  - controls are shown/hidden based on detected capabilities
- Model-family behavior currently used in practice:
  - `Base` models: custom voice cloning flow enabled
  - `CustomVoice` models: named speaker flow enabled
- Studio behavior:
  - model selector + language in first row
  - speaker selector in second row for both model families
  - first named speaker auto-selected when model requires named speakers
- Voices behavior:
  - voice extraction/presets enabled only when model supports cloning
  - speaker presets remain embedding-dimension aware to avoid mismatched reuse

### In progress / rough edges

- Packaging and onboarding are still developer-oriented.
- Runtime and model validation UX can be improved (clearer diagnostics in Setup).
- Linux path and runtime validation is not yet fully documented/tested.

## Feature matrix

| Feature | Base model family | CustomVoice model family |
|---|---|---|
| Text-to-speech generation | Yes | Yes |
| Custom voice cloning (reference WAV/embedding) | Yes | No |
| Instruction/style prompt | No (current Base models) | Yes (when capability is present) |
| Named speaker dropdown | No (current Base models) | Yes |

## Build and run workflow (Windows)

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

## Next milestones

1. Improve Setup validation:
- detect missing model files and show exact required filenames/dependencies per selected model.

2. Better generation diagnostics:
- surface backend errors with actionable hints (bad model dir, missing tokenizer/vocoder, etc.).

3. Speaker UX polish (named-speaker models):
- optional refresh button and loading state for speaker list retrieval.

4. Hybrid-capability model support:
- support models that expose both named speakers/instruction and cloning in one checkpoint, with explicit UI precedence rules.

5. Distribution:
- stable Windows package flow (CPU and CUDA variants).
