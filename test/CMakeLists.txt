add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain simple-cpp-base64-compiler_options simple-cpp-base64-lib)

include(Catch)
catch_discover_tests(tests)