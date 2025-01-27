#include "core.h"
#include "os_command.h"
#include "chdir_command.h"
#include <string>
#include <iostream>
#include "command_not_found_err.h"
#include <sstream>
void Sys::Core::SetupBuiltin()
{
  commands.push_back(std::make_unique<Sys::Commands::ChdirCommand>("cd",true, "change dir", true));
  commands.push_back(std::make_unique<Sys::Commands::OSCommand>("ls",true, "list dir", false));
}

Sys::Commands::Command* Sys::Core::GetSysCommand(std::string alias)
{ 

  std::string c;

  std::istringstream stream(alias);

  stream >> c; 

  for (std::vector<std::unique_ptr<Sys::Commands::Command>>::const_iterator it = commands.begin(); it != commands.end(); ++it) {
    if ((*it)->alias == c) {
      return it->get();  
    }
  }
  throw Sys::Errors::CommandNotFoundException(std::format("command not found: {0}", alias).c_str()) ;
}
