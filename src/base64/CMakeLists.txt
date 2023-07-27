add_library(simple-cpp-base64-lib alphabet.cpp encoder.cpp decoder.cpp)
target_link_libraries(simple-cpp-base64-lib PUBLIC simple-cpp-base64-compiler_options)
target_include_directories(simple-cpp-base64-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(simple-cpp-base64::lib ALIAS simple-cpp-base64-lib)