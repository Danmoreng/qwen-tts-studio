#include "qwen3_tts.h"
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <mutex>

#if defined(_WIN32)
#define QWEN_API __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#define QWEN_API __attribute__((visibility("default")))
#endif

using namespace qwen3_tts;

extern "C" {

#if defined(_WIN32)
static void dump_module_path(const char * module_name) {
    HMODULE mod = GetModuleHandleA(module_name);
    if (!mod) {
        fprintf(stderr, "[Wrapper] Module not loaded: %s\n", module_name);
        return;
    }

    char path_buf[MAX_PATH] = {0};
    DWORD len = GetModuleFileNameA(mod, path_buf, MAX_PATH);
    if (len == 0 || len >= MAX_PATH) {
        fprintf(stderr, "[Wrapper] Module loaded but path unavailable: %s\n", module_name);
        return;
    }
    fprintf(stderr, "[Wrapper] Module path: %s => %s\n", module_name, path_buf);
}
#endif

struct QwenContext {
    Qwen3TTS* engine;
    tts_result last_result;
};

QWEN_API void qwen3_tts_backend_init() {
    // Rely on engine's internal lazy initialization
    fprintf(stderr, "[Wrapper] Backend init called\n");
#if defined(_WIN32)
    dump_module_path("qwen3_tts.dll");
    dump_module_path("ggml.dll");
    dump_module_path("ggml-base.dll");
    dump_module_path("ggml-cpu.dll");
    dump_module_path("ggml-cuda.dll");
#endif
    fflush(stderr);
}

QWEN_API QwenContext* qwen3_tts_init(const char* model_dir) {
    if (!model_dir) return nullptr;
    
    fprintf(stderr, "[Wrapper] Initializing with: %s\n", model_dir);
    fflush(stderr);

    try {
        QwenContext* ctx = new QwenContext();
        ctx->engine = new Qwen3TTS();

        bool ok = ctx->engine->load_models(model_dir);

        if (ok) {
            fprintf(stderr, "[Wrapper] Load success\n");
            fflush(stderr);
            return ctx;
        }

        fprintf(stderr, "[Wrapper] Load failed: %s\n", ctx->engine->get_error().c_str());
        fflush(stderr);
        delete ctx->engine;
        delete ctx;
        return nullptr;
    } catch (const std::exception& e) {
        fprintf(stderr, "[Wrapper] Exception: %s\n", e.what());
        fflush(stderr);
        return nullptr;
    } catch (...) {
        fprintf(stderr, "[Wrapper] Unknown exception\n");
        fflush(stderr);
        return nullptr;
    }
}

QWEN_API const float* qwen3_tts_generate(
    QwenContext* ctx, 
    const char* text, 
    const char* reference_wav_path, 
    int* out_size
) {
    if (!ctx || !ctx->engine || !text) return nullptr;

    try {
        if (reference_wav_path && strlen(reference_wav_path) > 0) {
            ctx->last_result = ctx->engine->synthesize_with_voice(text, reference_wav_path);
        } else {
            ctx->last_result = ctx->engine->synthesize(text);
        }
        
        if (ctx->last_result.success) {
            *out_size = static_cast<int>(ctx->last_result.audio.size());
            return ctx->last_result.audio.data();
        } else {
            *out_size = 0;
            return nullptr;
        }
    } catch (...) {
        *out_size = 0;
        return nullptr;
    }
}

QWEN_API void qwen3_tts_free_audio(QwenContext* ctx) {
    if (ctx) {
        ctx->last_result.audio.clear();
        ctx->last_result.audio.shrink_to_fit();
    }
}

QWEN_API void qwen3_tts_destroy(QwenContext* ctx) {
    if (ctx) {
        delete ctx->engine;
        delete ctx;
    }
}

} // extern "C"
