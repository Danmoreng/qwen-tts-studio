# Qwen-TTS Studio

Qwen-TTS Studio is a desktop app (Compose Multiplatform) for local text-to-speech using a native C++ backend (`qwen3-tts.cpp` submodule).

## Screenshot

![Qwen-TTS Studio Screenshot](docs/images/studio-screenshot.png)

## Status

This project is still alpha, but model capability detection is integrated in the UI.

### Model capability detection

The app now detects capabilities from the loaded model metadata and adapts controls automatically:

- If model supports cloning:
  - Voices page can extract/save custom speaker presets.
  - Studio uses reference/embedding voices.
- If model supports named speakers:
  - Studio shows named speaker dropdown and selects first speaker by default.
- If model supports instruction:
  - Studio shows instruction field.

This allows different behavior for models like `0.6B-Base`, `1.7B-Base`, and `1.7B-CustomVoice` without hardcoding one static mode switch.

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

## Build from source (Linux)

1. Clone with submodules:
```bash
git clone --recursive https://github.com/Danmoreng/qwen-tts-studio.git
```

2. Build native backend (CPU):
```bash
chmod +x scripts/build-native.sh
./scripts/build-native.sh
```

3. Run desktop app:
```bash
chmod +x gradlew
./gradlew :composeApp:run
```

4. In `Setup`:
- Select `Model Directory`.
- Select `Model File Name` (detected `.gguf` list is provided).

## Notes

- You still need compatible local model files in your model directory.
- Speaker presets are embedding-dimension aware (`1024` vs `2048`) to avoid mismatched reuse.
- Some models require named speakers (for example CustomVoice); Studio auto-selects the first available speaker.
- App window now uses a custom icon from `composeApp/src/desktopMain/resources/icons/app-icon.svg`.

## Documentation

- Roadmap and implementation status: [docs/DEVELOPMENT_PLAN.md](docs/DEVELOPMENT_PLAN.md)

## License

MIT, see [LICENSE](LICENSE).
