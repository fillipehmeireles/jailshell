#pragma once

#include <string> 

namespace Sys {
  namespace Commands {
    class Command {
      public:
        Command(
            unsigned int ID,
            std::string al,
            bool os_cmd,
            std::string desc,
            bool ha 
            ):id(ID),alias(al),is_os_cmd(os_cmd),description(desc),has_args(ha){}
        virtual ~Command() = default; 
        unsigned int id;
        std::string alias;
        bool is_os_cmd;
        std::string description;
        bool has_args;
        virtual std::string Run() const = 0;
        virtual std::string RunWithArgs(const std::string args) const = 0;

    }; 
  } 
}
