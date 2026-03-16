# CMake generated Testfile for 
# Source directory: C:/Development/qwen-tts-studio/external/qwen3-tts-cpp
# Build directory: C:/Development/qwen-tts-studio/external/build-ninja/qwen3-tts-cpp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tokenizer_test "C:/Development/qwen-tts-studio/external/build-ninja/qwen3-tts-cpp/test_tokenizer.exe")
set_tests_properties(tokenizer_test PROPERTIES  WORKING_DIRECTORY "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp" _BACKTRACE_TRIPLES "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;267;add_test;C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;0;")
add_test(encoder_test "C:/Development/qwen-tts-studio/external/build-ninja/qwen3-tts-cpp/test_encoder.exe" "--tokenizer" "models/qwen3-tts-0.6b-f16.gguf" "--audio" "clone.wav" "--reference" "reference/ref_audio_embedding.bin")
set_tests_properties(encoder_test PROPERTIES  WORKING_DIRECTORY "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp" _BACKTRACE_TRIPLES "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;271;add_test;C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;0;")
add_test(transformer_test "C:/Development/qwen-tts-studio/external/build-ninja/qwen3-tts-cpp/test_transformer.exe")
set_tests_properties(transformer_test PROPERTIES  WORKING_DIRECTORY "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp" _BACKTRACE_TRIPLES "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;275;add_test;C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;0;")
add_test(decoder_test "C:/Development/qwen-tts-studio/external/build-ninja/qwen3-tts-cpp/test_decoder.exe")
set_tests_properties(decoder_test PROPERTIES  WORKING_DIRECTORY "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp" _BACKTRACE_TRIPLES "C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;279;add_test;C:/Development/qwen-tts-studio/external/qwen3-tts-cpp/CMakeLists.txt;0;")
subdirs("ggml")
