#include "os_command.h"
#include <iostream>
#include "command.h"
#include "posix.h"
#include <vector> 
#include <memory>

Sys::Commands::OSCommand::OSCommand (
    std::string al,
    bool os_cmd,
    std::string desc,
    bool ha
    ):Sys::Commands::Command( al, os_cmd,desc,ha){}

std::unique_ptr<std::string> Sys::Commands::OSCommand::RunWithArgs(const std::vector<std::string> args) const 
{
  return nullptr;
}

std::unique_ptr<std::string> Sys::Commands::OSCommand::Run() const 
{
  try {  
    std::string result = POSIX_RawCommand(alias.c_str());
    return std::make_unique<std::string>(result);
  }
  catch (const std::exception& e) {
    return std::make_unique<std::string>(e.what());
  }
}
