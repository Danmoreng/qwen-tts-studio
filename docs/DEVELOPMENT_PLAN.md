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
- Model variant switch in UI:
  - `0.6B` mode
  - `1.7B` mode
- Mode-dependent behavior:
  - `0.6B`: custom voices enabled (reference/embedding path flow)
  - `1.7B`: instruction input + named speakers, custom voices disabled

### In progress / rough edges

- Packaging and onboarding are still developer-oriented.
- Runtime and model validation UX can be improved (clearer diagnostics in Setup).
- Linux path and runtime validation is not yet fully documented/tested.

## Feature matrix

| Feature | 0.6B | 1.7B |
|---|---|---|
| Text-to-speech generation | Yes | Yes |
| Custom voice cloning (reference WAV/embedding) | Yes | No (intentionally disabled in UI) |
| Instruction/style prompt | No | Yes |
| Named speaker dropdown | No | Yes |

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
- Pick `Model Variant` (`0.6B` or `1.7B`)

## Next milestones

1. Improve Setup validation:
- detect missing model files and show exact required filenames per mode.

2. Better generation diagnostics:
- surface backend errors with actionable hints (bad model dir, missing tokenizer/vocoder, etc.).

3. Speaker UX polish (1.7B):
- optional refresh button and loading state for speaker list retrieval.

4. Distribution:
- stable Windows package flow (CPU and CUDA variants).
