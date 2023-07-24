#ifndef SIMPLE_BASE64_TOOL_ALPHABET_HPP
#define SIMPLE_BASE64_TOOL_ALPHABET_HPP

#include <array>

namespace simple_cpp::base64 {

constinit extern std::array<char, 64> encodeAlphabet;
constinit extern std::array<char, 256> decodeAlphabet;
} // namespace simple_cpp::base64

#endif // SIMPLE_BASE64_TOOL_ALPHABET_HPP
