cmake_minimum_required(VERSION 3.22.1)

project(simple-cpp-base64 VERSION 0.2.1)

cmake_policy(SET CMP0048 NEW)
add_library(simple-cpp-compiler_options INTERFACE)
target_compile_features(simple-cpp-compiler_options INTERFACE cxx_std_20)

add_subdirectory(src/base64)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  add_subdirectory(vendor/CLI11)
  add_executable(simple-base64-tool main.cpp)
  target_link_libraries(simple-base64-tool CLI11::CLI11 simple-cpp-base64-lib simple-cpp-compiler_options)
  set_target_properties(simple-base64-tool PROPERTIES OUTPUT_NAME simple-base64-${CMAKE_PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION})

  enable_testing()
  add_subdirectory(vendor/Catch2)
  add_subdirectory(test)
  include(CTest)

  add_test(NAME base64-tool-encode COMMAND simple-base64-tool test)
  set_property(TEST base64-tool-encode PROPERTY PASS_REGULAR_EXPRESSION dGVzdA==)

  add_test(NAME base64-tool-decode COMMAND simple-base64-tool d dGVzdA==)
  set_property(TEST base64-tool-decode PROPERTY PASS_REGULAR_EXPRESSION test)
endif()