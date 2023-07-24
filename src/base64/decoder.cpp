#include "decoder.hpp"

#include "alphabet.hpp"

namespace simple_cpp::base64 {

std::string decode(const std::string_view &input) {
  auto end  = input.end();
  while (end != input.begin() && *(end - 1) == '=') {
    --end;
  }

  std::string result{};

  auto write = [&result, buffer = 0, bufferBits = 0](const auto &bits) mutable {
    buffer <<= 6;
    bufferBits +=6;
    buffer += bits;
    while (bufferBits >= 8) {
      result += static_cast<char>((buffer >> (bufferBits - 8)) & 0xFF);
      bufferBits -= 8;
      buffer &= ~(0xFF << bufferBits);
    }
  };

  for (auto i = input.begin(); i != end; ++i) {
    write(simple_cpp::base64::decodeAlphabet[*i]);
  }

  return result;
}
}
