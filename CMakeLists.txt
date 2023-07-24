cmake_minimum_required(VERSION 3.22.1)

project(simple-cpp-base64 VERSION 1.0)

cmake_policy(SET CMP0048 NEW)
add_library(compiler_options INTERFACE)
target_compile_features(compiler_options INTERFACE cxx_std_20)

add_subdirectory(vendor/CLI11)
add_subdirectory(src/base64)

add_executable(simple-base64 main.cpp)
target_link_libraries(simple-base64 CLI11::CLI11 simple-cpp-base64-lib compiler_options)

enable_testing()
add_subdirectory(vendor/Catch2)
add_subdirectory(test)
include(CTest)

add_test(base64-tool-encode simple-base64 test)
set_property(TEST base64-tool-encode PROPERTY PASS_REGULAR_EXPRESSION dGVzdA==)

add_test(base64-tool-decode simple-base64 d dGVzdA==)
set_property(TEST base64-tool-decode PROPERTY PASS_REGULAR_EXPRESSION test)