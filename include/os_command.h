#pragma once

#include "command.h"
#include <string>

namespace Sys {
  namespace Commands {
    class OSCommand : public Command {
      public:
        OSCommand(
            unsigned int ID,
            std::string al,
            bool os_cmd,
            std::string desc,
            bool ha 
            );

        //TODO: args as string?
        std::string RunWithArgs(const std::string args) const override; 
        std::string Run() const override ;
    };

  }

}


