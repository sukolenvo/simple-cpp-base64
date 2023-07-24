#include "alphabet.hpp"
#include "encoder.hpp"

namespace simple_cpp::base64 {

std::string encode(const std::string_view &input) {
  unsigned int buffer = 0;
  int bufferBits = 0;
  auto stream = input.begin();
  auto readNext = [&]() {
    if (bufferBits < 6 && stream != input.end()) {
      const unsigned char c = *stream++;
      buffer <<= sizeof(c) * 8;
      buffer |= c;
      bufferBits += sizeof(c) * 8;
    }
    if (bufferBits < 6) {
      buffer <<= 6 - bufferBits;
      bufferBits = 0;
      return static_cast<int>(buffer);
    }
    const int next = (buffer >> (bufferBits - 6));
    bufferBits -= 6;
    buffer &= ~(~0U << bufferBits);
    return next;
  };
  std::string result{};
  while (stream != input.end() || bufferBits > 0) {
    result += simple_cpp::base64::encodeAlphabet[readNext()];
  }
  for (int i = 0; (input.size() + i) % 3 != 0; ++i) {
    result += '=';
  }
  return result;
}
}
