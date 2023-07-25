#include "alphabet.hpp"
#include <string>

namespace simple_cpp::base64 {

constexpr auto buildEncodeAlphabet() {
  std::array<char, 64> result{0};
  std::string s{
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
  for (int i = 0; i < s.size(); ++i) {
    result[i] = s[i];
  }
  return result;
}

constexpr auto buildDecodeAlphabet() {
  std::array<char, 256> result{0};
  auto encodeAlphabet = buildEncodeAlphabet();
  for (char i = 0; i < encodeAlphabet.size(); ++i) {
    result[encodeAlphabet[i]] = i;
  }
  return result;
}

constinit std::array<char, 64> encodeAlphabet = buildEncodeAlphabet();
constinit std::array<char, 256> decodeAlphabet = buildDecodeAlphabet();

}