#pragma once

#include <string> 
#include <vector>
#include <memory>

namespace Sys {
  namespace Commands {
    class Command {
      public:
        Command(
            std::string al,
            bool os_cmd,
            std::string desc,
            bool ha
            ):alias(al),is_os_cmd(os_cmd),description(desc),has_args(ha){}
        virtual ~Command() = default; 

        unsigned int id;
        std::string alias;
        bool is_os_cmd;
        std::string description;
        bool has_args;

        virtual std::unique_ptr<std::string>
          Run() const = 0;
        virtual std::unique_ptr<std::string>
          RunWithArgs(const std::vector<std::string> args) const = 0;
    }; 
  } 
}
