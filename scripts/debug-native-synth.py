import argparse
import ctypes
import os
from pathlib import Path


class Params(ctypes.Structure):
    _fields_ = [
        ("max_audio_tokens", ctypes.c_int32),
        ("temperature", ctypes.c_float),
        ("top_p", ctypes.c_float),
        ("top_k", ctypes.c_int32),
        ("n_threads", ctypes.c_int32),
        ("print_progress", ctypes.c_int32),
        ("print_timing", ctypes.c_int32),
        ("repetition_penalty", ctypes.c_float),
        ("language_id", ctypes.c_int32),
        ("instruction", ctypes.c_char_p),
        ("speaker", ctypes.c_char_p),
    ]


class Result(ctypes.Structure):
    _fields_ = [
        ("audio", ctypes.POINTER(ctypes.c_float)),
        ("audio_len", ctypes.c_int32),
        ("sample_rate", ctypes.c_int32),
        ("success", ctypes.c_int32),
        ("error_msg", ctypes.c_char_p),
        ("t_total_ms", ctypes.c_int64),
    ]


class Capabilities(ctypes.Structure):
    _fields_ = [
        ("loaded", ctypes.c_int32),
        ("supports_voice_clone", ctypes.c_int32),
        ("supports_named_speakers", ctypes.c_int32),
        ("supports_instruction", ctypes.c_int32),
        ("speaker_embedding_dim", ctypes.c_int32),
        ("speaker_count", ctypes.c_int32),
        ("model_kind", ctypes.c_int32),
    ]


def add_dll_dir(path: Path) -> None:
    if path.exists():
        os.add_dll_directory(str(path))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dll", default="qwen3_tts.dll")
    parser.add_argument("--model-dir", required=True)
    parser.add_argument("--model-name", required=True)
    parser.add_argument("--speaker", default="aiden")
    parser.add_argument("--reference-wav")
    parser.add_argument("--speaker-embedding")
    parser.add_argument("--extract-embedding-out")
    parser.add_argument("--text", default="Hallo, dies ist ein kurzer Test.")
    parser.add_argument("--tokens", type=int, default=96)
    parser.add_argument("--no-repo-dll-dir", action="store_true")
    args = parser.parse_args()

    repo_root = Path(__file__).resolve().parents[1]
    cuda = Path(os.environ.get("CUDA_PATH", r"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v13.3"))
    dll_path = (repo_root / args.dll).resolve()
    add_dll_dir(dll_path.parent)
    add_dll_dir(dll_path.parent / "bin")
    if not args.no_repo_dll_dir:
        add_dll_dir(repo_root)
    add_dll_dir(cuda / "bin")
    add_dll_dir(cuda / "bin" / "x64")

    dll = ctypes.CDLL(str(dll_path))
    dll.qwen3_tts_init.restype = ctypes.c_void_p
    dll.qwen3_tts_free.argtypes = [ctypes.c_void_p]
    dll.qwen3_tts_load_models_with_name.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p]
    dll.qwen3_tts_load_models_with_name.restype = ctypes.c_int32
    dll.qwen3_tts_get_model_capabilities.argtypes = [ctypes.c_void_p]
    dll.qwen3_tts_get_model_capabilities.restype = Capabilities
    dll.qwen3_tts_get_available_speakers.argtypes = [ctypes.c_void_p]
    dll.qwen3_tts_get_available_speakers.restype = ctypes.c_void_p
    dll.qwen3_tts_free_string.argtypes = [ctypes.c_void_p]
    dll.qwen3_tts_synthesize.argtypes = [ctypes.c_void_p, ctypes.c_char_p, Params]
    dll.qwen3_tts_synthesize.restype = Result
    dll.qwen3_tts_synthesize_with_voice.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, Params]
    dll.qwen3_tts_synthesize_with_voice.restype = Result
    dll.qwen3_tts_synthesize_with_speaker_embedding.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, Params]
    dll.qwen3_tts_synthesize_with_speaker_embedding.restype = Result
    dll.qwen3_tts_extract_speaker_embedding.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p]
    dll.qwen3_tts_extract_speaker_embedding.restype = ctypes.c_int32
    dll.qwen3_tts_free_result.argtypes = [Result]

    ctx = dll.qwen3_tts_init()
    if not ctx:
        print("init failed")
        return 2

    try:
        ok = dll.qwen3_tts_load_models_with_name(
            ctx,
            str(Path(args.model_dir)).encode("utf-8"),
            args.model_name.encode("utf-8"),
        )
        print(f"load={ok}")
        if not ok:
            return 3

        caps = dll.qwen3_tts_get_model_capabilities(ctx)
        print(
            "caps="
            f"loaded:{caps.loaded} clone:{caps.supports_voice_clone} "
            f"named:{caps.supports_named_speakers} instruction:{caps.supports_instruction} "
            f"speaker_count:{caps.speaker_count} kind:{caps.model_kind}"
        )
        speakers_ptr = dll.qwen3_tts_get_available_speakers(ctx)
        if speakers_ptr:
            try:
                speakers = ctypes.cast(speakers_ptr, ctypes.c_char_p).value.decode("utf-8", errors="replace")
                print("speakers=" + ",".join(speakers.splitlines()[:12]))
            finally:
                dll.qwen3_tts_free_string(speakers_ptr)

        if args.extract_embedding_out:
            if not args.reference_wav:
                print("extract=failed missing --reference-wav")
                return 5
            ok = dll.qwen3_tts_extract_speaker_embedding(
                ctx,
                str(Path(args.reference_wav)).encode("utf-8"),
                str(Path(args.extract_embedding_out)).encode("utf-8"),
            )
            print(f"extract=done success:{ok} out:{args.extract_embedding_out}")
            return 0 if ok else 5

        params = Params(
            args.tokens,
            ctypes.c_float(0.0),
            ctypes.c_float(1.0),
            1,
            4,
            1,
            1,
            ctypes.c_float(1.05),
            2053,
            "natuerlich und klar".encode("utf-8"),
            args.speaker.encode("utf-8"),
        )
        print("synth=start", flush=True)
        if args.speaker_embedding:
            params.speaker = None
            result = dll.qwen3_tts_synthesize_with_speaker_embedding(
                ctx,
                args.text.encode("utf-8"),
                str(Path(args.speaker_embedding)).encode("utf-8"),
                params,
            )
        elif args.reference_wav:
            params.speaker = None
            result = dll.qwen3_tts_synthesize_with_voice(
                ctx,
                args.text.encode("utf-8"),
                str(Path(args.reference_wav)).encode("utf-8"),
                params,
            )
        else:
            result = dll.qwen3_tts_synthesize(ctx, args.text.encode("utf-8"), params)
        print(
            f"synth=done success:{result.success} len:{result.audio_len} "
            f"sr:{result.sample_rate} ms:{result.t_total_ms}"
        )
        if result.error_msg:
            print("error=" + result.error_msg.decode("utf-8", errors="replace"))
        dll.qwen3_tts_free_result(result)
        return 0 if result.success else 4
    finally:
        dll.qwen3_tts_free(ctx)


if __name__ == "__main__":
    raise SystemExit(main())
