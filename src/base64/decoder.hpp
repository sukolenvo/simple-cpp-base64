#ifndef SIMPLE_CPP_BASE64_DECODER_HPP
#define SIMPLE_CPP_BASE64_DECODER_HPP

#include <string>
#include <string_view>

namespace simple_cpp::base64 {
std::string decode(const std::string_view &input);
}

#endif // SIMPLE_CPP_BASE64_DECODER_HPP
