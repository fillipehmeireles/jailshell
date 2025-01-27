#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <iostream> 

std::string POSIX_RawCommand(const std::string cmd) {
  std::array<char, 512> buffer;
  std::string result;

  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);

  if (!pipe) {
    throw std::runtime_error("popen failed!");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  return result;
}
