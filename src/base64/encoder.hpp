#ifndef SIMPLE_CPP_BASE64_ENCODER_HPP
#define SIMPLE_CPP_BASE64_ENCODER_HPP

#include <string>
#include <string_view>

#include <SimpleCppBase64_Export.h>

namespace simple_cpp::base64 {
std::string SimpleCppBase64_EXPORT encode(const std::string_view &input);
}

#endif // SIMPLE_CPP_BASE64_ENCODER_HPP
