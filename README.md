# Simple C++ base64 tool

C++ library for encoding to/decoding from Base64.

## Tool usage

```bash
$ simple-base64 -h

$ simple-base64 test
dGVzdA==

$ simple-base64 -f test.txt
MTIzCg==

$ simple-base64 d dGVzdA==
test

$ simple-base64 d -f test.txt
input
```

## Library usage

```cpp
#include <decoder.hpp>

std::cout << simple_cpp::base64::encode("sample input");
```

## Cmake integration

### Git submodule 
Checkout project as a Git submodule, then update `CMakeLists.txt`:
```cmake
add_subdirectory(vendor/simple-cpp-base64)

target_link_libraries(target simple-cpp-base64::lib) 
```

### FetchContent
```cmake
include(FetchContent)

FetchContent_Declare(
    simple-cpp-base64
    GIT_REPOSITORY https://github.com/sukolenvo/simple-cpp-base64.git
    GIT_TAG        v0.2
)

FetchContent_MakeAvailable(simple-cpp-base64)

target_link_libraries(target simple-cpp-base64::lib) 
```

## Build project

```bash
git submodule update --init
cmake -S . -B build
cmake --build build -- -j 8
ctest --test-dir build
```