#include <string>

#include <encoder.hpp>
#include <decoder.hpp>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  const std::string input(reinterpret_cast<const char *>(Data), Size);
  const auto encoded = simple_cpp::base64::encode(input);
  const auto decoded = simple_cpp::base64::decode(encoded);
  return decoded == input ? 0 : -1;
}