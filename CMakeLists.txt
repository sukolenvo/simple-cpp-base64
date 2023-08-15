cmake_minimum_required(VERSION 3.22.1)

project(simple-cpp-base64 VERSION 2.0.0)

cmake_policy(SET CMP0048 NEW)

OPTION(SIMPLE_CPP_BASE64_WARNINGS_AS_ERRORS "Treat compiler warnings as errors")
add_library(simple-cpp-base64-compiler_options INTERFACE)
target_compile_features(simple-cpp-base64-compiler_options INTERFACE cxx_std_20)
if (MSVC)
  target_compile_options(simple-cpp-base64-compiler_options INTERFACE /W4)
  if (SIMPLE_CPP_BASE64_WARNINGS_AS_ERRORS)
    target_compile_options(simple-cpp-base64-compiler_options INTERFACE /WX)
  endif ()
else ()
  target_compile_options(simple-cpp-base64-compiler_options INTERFACE -Wall -Wextra -Wpedantic)
  if (SIMPLE_CPP_BASE64_WARNINGS_AS_ERRORS)
    target_compile_options(simple-cpp-base64-compiler_options INTERFACE -Werror)
  endif ()
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()

add_subdirectory(src)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(FetchContent)
  FetchContent_Declare(
      CLI11
      GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
      GIT_TAG v2.3.2
      GIT_SHALLOW TRUE
  )
  FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG v3.4.0
      GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(CLI11 Catch2)

  add_executable(simple-base64-tool main.cpp)
  if (NOT BUILD_SHARED_LIBS)
    if (MSVC)
      set_property(TARGET simple-base64-tool PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    else ()
      set(LINK_FLAGS -static)
    endif ()
  endif ()
  target_link_libraries(simple-base64-tool CLI11::CLI11 simple-cpp-base64-lib simple-cpp-base64-compiler_options ${LINK_FLAGS})
  set_target_properties(simple-base64-tool PROPERTIES OUTPUT_NAME simple-base64-${CMAKE_PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})

  enable_testing()
  add_subdirectory(test)
  add_subdirectory(fuzz_test)
  include(CTest)

  add_test(NAME base64-tool-encode COMMAND simple-base64-tool test)
  set_property(TEST base64-tool-encode PROPERTY PASS_REGULAR_EXPRESSION dGVzdA==)

  add_test(NAME base64-tool-decode COMMAND simple-base64-tool d dGVzdA==)
  set_property(TEST base64-tool-decode PROPERTY PASS_REGULAR_EXPRESSION test)
endif ()