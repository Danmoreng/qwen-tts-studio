# Qwen-TTS Studio

Qwen-TTS Studio is a desktop app (Compose Multiplatform) for local text-to-speech using a native C++ backend (`qwen3-tts.cpp` submodule).

## Status

This project is still alpha, but both major model variants are now integrated in the UI.

### Supported model modes

- `0.6B` mode:
  - Voice cloning from reference WAV.
  - Speaker embedding extraction and preset management.
  - No instruction UI.
- `1.7B` mode:
  - Style instructions.
  - Named speaker selection from model-provided speaker list.
  - Custom voice cloning is intentionally disabled in this mode.

The model mode is selected in the app via dropdown (`0.6B` / `1.7B`), and the matching model file is applied automatically.

## Tech stack

- Frontend: Kotlin + Compose Multiplatform (desktop)
- Native backend: `external/qwen3-tts-cpp` (C++/ggml)
- Bridge: JNI (`qwen3_tts.dll` loaded by desktop app)

## Build from source (Windows)

1. Clone with submodules:
```bash
git clone --recursive https://github.com/Danmoreng/qwen-tts-studio.git
```

2. Build native backend (CPU):
```powershell
pwsh -ExecutionPolicy Bypass -File .\scripts\build-native.ps1
```

3. Run desktop app:
```powershell
.\gradlew.bat :composeApp:run
```

4. In `Setup`:
- Select `Model Directory`.
- Select `Model Variant` (`0.6B` or `1.7B`).

## Notes

- You still need compatible local model files in your model directory.
- In `1.7B`, use named speakers from the speaker dropdown in Studio.
- In `0.6B`, use Voices page for custom speaker presets.

## Documentation

- Roadmap and implementation status: [docs/DEVELOPMENT_PLAN.md](docs/DEVELOPMENT_PLAN.md)

## License

MIT, see [LICENSE](LICENSE).
