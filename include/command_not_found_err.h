#pragma once

#include <exception>
#include <string>

namespace Sys{
  namespace Errors{
    class CommandNotFoundException : public std::exception {
      private:
        std::string message;

      public:
        CommandNotFoundException(const std::string& msg) : message(msg) {}

        virtual const char* what() const noexcept override {
          return message.c_str();
        }
    };
  }
}
