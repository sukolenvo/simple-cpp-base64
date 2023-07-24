#include <string>
#include <iostream>
#include <fstream>

#include "CLI/CLI.hpp"

#include "encoder.hpp"
#include "decoder.hpp"

int main(int argc, char** argv) {
  CLI::App app{"Simple C++ base64 tool."};
  app.require_option();

  auto* encode = app.add_subcommand("e", "Encode input into base64")->fallthrough(true);
  auto* decode = app.add_subcommand("d", "Decode input from base64")->excludes(encode)->fallthrough(true);
  std::string filename{};
  auto* file = app.add_option("-f,--file", filename, "File content to encode.");
  std::string input{};
  app.add_option("input", input, "Value to encode")->excludes(file);

  CLI11_PARSE(app, argc, argv);

  if (!file->empty()) {
    std::ifstream f(filename);
    input = std::string((std::istreambuf_iterator<char>(f)),
                        std::istreambuf_iterator<char>());
  }

  if (decode->count() > 0) {
    std::cout << simple_cpp::base64::decode(input);
  } else {
    std::cout << simple_cpp::base64::encode(input);
  }
  return 0;
}