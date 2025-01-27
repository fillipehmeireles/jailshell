#pragma once

#include "command.h"
#include <string>
#include <vector>
#include <memory> 

namespace Sys {
  namespace Commands {
    class OSCommand : public Command {
      public:
        OSCommand(
            std::string al,
            bool os_cmd,
            std::string desc,
            bool ha 
            );

         std::unique_ptr<std::string>
         Run() const override;
         std::unique_ptr<std::string>
          RunWithArgs(const std::vector<std::string> args) const override;
    };

  }

}


