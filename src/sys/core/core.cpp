#include "core.h"
#include "command.h"
#include <string>
#include <iostream>
#include "command_not_found_err.h"

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
      return cmd;
    }
  }
  throw Sys::Errors::CommandNotFoundException(std::format("command not found: {0}", alias).c_str()) ;
}
