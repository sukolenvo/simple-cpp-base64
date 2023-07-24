#ifndef SIMPLE_CPP_BASE64_ENCODER_HPP
#define SIMPLE_CPP_BASE64_ENCODER_HPP

#include <string>
#include <string_view>

namespace simple_cpp::base64 {
std::string encode(const std::string_view &input);
}

#endif // SIMPLE_CPP_BASE64_ENCODER_HPP
