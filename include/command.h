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
            ); 
        unsigned int id;
        std::string alias;
        bool is_os_cmd;
        std::string description;
        bool has_args;
        std::string Run();
        std::string RunWithArgs(char** args);
      private:

    }; 
  } 
}
