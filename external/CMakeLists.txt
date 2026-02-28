cmake_minimum_required(VERSION 3.14)
project(qwen3-tts-wrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forward CUDA option to the submodule
option(QWEN3_TTS_CUDA "Enable CUDA backend" ON)

# Add the submodule
add_subdirectory(qwen3-tts-cpp)

# Create the shared library from our wrapper
add_library(qwen3_tts_shared SHARED qwen3_tts_wrapper.cpp)

# Set the output name to match what JNA expects: qwen3_tts.dll
set_target_properties(qwen3_tts_shared PROPERTIES OUTPUT_NAME "qwen3_tts")

# Include directories from the submodule
target_include_directories(qwen3_tts_shared PRIVATE 
    qwen3-tts-cpp/src
    qwen3-tts-cpp/ggml/include
)

# Link against the static library produced by the submodule
target_link_libraries(qwen3_tts_shared PRIVATE qwen3_tts)

# Export symbols for Windows
if(WIN32)
    target_compile_definitions(qwen3_tts_shared PRIVATE COMPILING_DLL)
endif()
