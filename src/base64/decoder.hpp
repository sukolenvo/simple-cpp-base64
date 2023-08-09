#ifndef SIMPLE_CPP_BASE64_DECODER_HPP
#define SIMPLE_CPP_BASE64_DECODER_HPP

#include <string>
#include <string_view>

#include <SimpleCppBase64_Export.h>

namespace simple_cpp::base64 {
std::string SimpleCppBase64_EXPORT decode(const std::string_view &input);
}

#endif // SIMPLE_CPP_BASE64_DECODER_HPP
