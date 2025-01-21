#pragma once

#include <vector>
#include "command.h"
#include <string>

namespace Sys {
  class Core {
    public:
      void SetupBuiltin();
      Sys::Commands::Command GetSysCommand(std::string alias);
    private: 
      std::vector<Sys::Commands::Command> commands;
  };
}
