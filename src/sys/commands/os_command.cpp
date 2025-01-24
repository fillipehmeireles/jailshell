#include "os_command.h"
#include <iostream>
#include "command.h"

Sys::Commands::OSCommand::OSCommand (
    unsigned int ID,
    std::string al,
    bool os_cmd,
    std::string desc,
    bool ha
    ):Sys::Commands::Command(ID, al, os_cmd,desc,ha){}

std::string Sys::Commands::OSCommand::RunWithArgs(const std::string args) const 
{
  return std::format("running os command with args: {0}", args);
}

std::string Sys::Commands::OSCommand::Run() const 
{
  return "running os command\n";
}
