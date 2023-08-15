add_executable(tests test.cpp)

if (NOT BUILD_SHARED_LIBS)
  if (MSVC)
    set_property(TARGET tests PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  endif ()
endif ()
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain simple-cpp-base64-compiler_options simple-cpp-base64-lib)

include(Catch)
catch_discover_tests(tests)