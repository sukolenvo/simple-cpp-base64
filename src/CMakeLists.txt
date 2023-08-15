option(BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
set(LIB_TYPE STATIC)
if (BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif ()
include(GenerateExportHeader)

file(GLOB source base64/*.cpp)

add_library(simple-cpp-base64-lib ${LIB_TYPE} ${source})
target_link_libraries(simple-cpp-base64-lib PRIVATE simple-cpp-base64-compiler_options)
target_include_directories(simple-cpp-base64-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(simple-cpp-base64-lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
generate_export_header(simple-cpp-base64-lib
  BASE_NAME SimpleCppBase64
  EXPORT_MACRO_NAME SimpleCppBase64_EXPORT
  EXPORT_FILE_NAME SimpleCppBase64_Export.h
  STATIC_DEFINE SimpleCppBase64_BUILT_AS_STATIC)

add_library(simple-cpp-base64::lib ALIAS simple-cpp-base64-lib)