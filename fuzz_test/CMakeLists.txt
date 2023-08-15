OPTION(SIMPLE_CPP_BASE64_FUZZ_TESTING "Enable fuzz testing")
if (SIMPLE_CPP_BASE64_FUZZ_TESTING)
  add_executable(fuzz_tester fuzz_tester.cpp)
  target_link_libraries(fuzz_tester PUBLIC simple-cpp-base64-compiler_options simple-cpp-base64-lib -fsanitize=fuzzer,undefined,address)
  target_compile_options(fuzz_tester PRIVATE -fsanitize=fuzzer,undefined,address)

  if (NOT BUILD_SHARED_LIBS)
    if (MSVC)
      set_property(TARGET fuzz_tester PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif ()
  endif ()

  SET(SIMPLE_CPP_BASE64_FUZZ_RUNTIME 10 CACHE STRING "Number of seconds to run fuzz testing")

  add_test(NAME fuzz_tester_run COMMAND fuzz_tester -max_total_time=${SIMPLE_CPP_BASE64_FUZZ_RUNTIME})
endif ()