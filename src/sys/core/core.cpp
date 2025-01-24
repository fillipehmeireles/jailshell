#include "core.h"
#include "os_command.h"
#include <string>
#include <iostream>
#include "command_not_found_err.h"

void Sys::Core::SetupBuiltin()
{
  commands.push_back(std::make_unique<Sys::Commands::OSCommand>(1,"ls",true, "list dir", false));
}

Sys::Commands::Command* Sys::Core::GetSysCommand(std::string alias)
{
  for (std::vector<std::unique_ptr<Sys::Commands::Command>>::const_iterator it = commands.begin(); it != commands.end(); ++it) {
    if ((*it)->alias == alias) {
      return it->get();  
    }
  }
  throw Sys::Errors::CommandNotFoundException(std::format("command not found: {0}", alias).c_str()) ;
}
