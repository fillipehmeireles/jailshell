#include "command.h"
#include <string>
#include <iostream> 

Sys::Commands::Command::Command(
    unsigned int ID,
    std::string al,
    bool os_cmd,
    std::string desc,
    bool ha 
    ): 
  id(ID), 
  alias(al), 
  is_os_cmd(os_cmd),
  description(desc),
  has_args(ha){}

std::string Sys::Commands::Command::Run() 
{
  return "running command\n";
}

std::string Sys::Commands::Command::RunWithArgs(char** args)
{
    return std::format("running command with args: {0}", args[0]);
}
