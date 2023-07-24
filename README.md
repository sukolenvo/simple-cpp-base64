# Simple C++ base64 tool

C++ library for encoding to/decoding from Base64.

## Build

```bash
git submodule update --init
cmake -S . -B build
cmake --build build -- -j 8
ctest --test-dir build
```