#include <tuple>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <decoder.hpp>
#include <encoder.hpp>

TEST_CASE("encode-decode")
{
  auto task = GENERATE(std::make_pair("1", "MQ=="),
    std::make_pair("12", "MTI="),
    std::make_pair("test", "dGVzdA=="),
    std::make_pair("abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM',./"
                   ";[]{}@\"abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM,./;[]{}@%^&*()_+123456789",
      "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXpRV0VSVFlVSU9QQVNERkdISktMWlhDVkJOTScsLi87W117fUAiYWJjZGVmZ2hpamtsbW5vcHFyc3R1"
      "dnd4eXpRV0VSVFlVSU9QQVNERkdISktMWlhDVkJOTSwuLztbXXt9QCVeJiooKV8rMTIzNDU2Nzg5"),
    std::make_pair("123", "MTIz"),
    std::make_pair("utf8 support: тест", "dXRmOCBzdXBwb3J0OiDRgtC10YHRgg=="));
  CAPTURE(task.first);
  REQUIRE(simple_cpp::base64::encode(task.first) == task.second);
  REQUIRE(simple_cpp::base64::decode(task.second) == task.first);
}