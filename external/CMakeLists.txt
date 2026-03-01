cmake_minimum_required(VERSION 3.14)
if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()
project(qwen3-tts-wrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Avoid binding native code to the JVM-bundled msvcp/vcruntime DLLs.
# This prevents CRT ABI/runtime conflicts when loaded inside JBR.
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "" FORCE)
endif()

# Forward CUDA option to the submodule
option(QWEN3_TTS_CUDA "Enable CUDA backend" OFF)
if(QWEN3_TTS_CUDA)
    set(GGML_CUDA ON CACHE BOOL "" FORCE)
else()
    set(GGML_CUDA OFF CACHE BOOL "" FORCE)
endif()

# Enable JNI
find_package(JNI REQUIRED)

# Add the submodule
set(QWEN3_TTS_BUILD_SHARED OFF CACHE BOOL "" FORCE)
add_subdirectory(qwen3-tts-cpp)

# Create the shared library from our JNI/C API
# We name it qwen3_tts.dll (the main target)
add_library(qwen3_tts_shared SHARED 
    qwen3-tts-cpp/src/qwen3_tts_jni.cpp
)

# Set the output name to match what JNA/JNI expects: qwen3_tts.dll.
# On Windows + Ninja (single-config), avoid import-lib name collision with
# the static submodule target `qwen3_tts` (both would otherwise emit qwen3_tts.lib).
set_target_properties(qwen3_tts_shared PROPERTIES
    OUTPUT_NAME "qwen3_tts"
    ARCHIVE_OUTPUT_NAME "qwen3_tts_jni_import"
)

# Include directories
target_include_directories(qwen3_tts_shared PRIVATE 
    qwen3-tts-cpp/src
    qwen3-tts-cpp/ggml/include
    ${JNI_INCLUDE_DIRS}
)

# Link against the static library produced by the submodule
target_link_libraries(qwen3_tts_shared PRIVATE qwen3_tts ${JNI_LIBRARIES})

# Export symbols for Windows
if(WIN32)
    target_compile_definitions(qwen3_tts_shared PRIVATE COMPILING_DLL)
    target_compile_definitions(qwen3_tts_shared PRIVATE QWEN3_TTS_EXPORT)
endif()
