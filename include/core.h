#pragma once

#include <vector>
#include "os_command.h"
#include <string>
namespace Sys {
  class Core {
    public:
      void SetupBuiltin();
      Sys::Commands::Command* GetSysCommand(std::string alias);
    private: 
      std::vector<std::unique_ptr<Sys::Commands::Command>> commands;
  };
}
