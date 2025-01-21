#include "core.h"
#include "command.h"
#include <string>
#include <iostream>

void Sys::Core::SetupBuiltin()
{
  Sys::Commands::Command ls(1,"ls",true, "list dir", false);
  this->commands.push_back(ls);
}

Sys::Commands::Command Sys::Core::GetSysCommand(std::string alias)
{
  for(Sys::Commands::Command cmd : commands) {
    if((cmd.alias.compare(alias)) == 0)
    {
      std::cout << cmd.alias;
      return cmd;
    }
  }
  // TODO: Create custom exception
  throw std::runtime_error(std::format("command not found: {0}", alias));
}
