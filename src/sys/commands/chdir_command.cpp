#include "chdir_command.h"
#include <iostream>
#include "command.h"
#include <memory>
#include <vector>
#include <string> 
#include <unistd.h>
#include <filesystem>
#include <cerrno> 

Sys::Commands::ChdirCommand::ChdirCommand (
    std::string al,
    bool os_cmd,
    std::string desc,
    bool ha
    ):Sys::Commands::Command( al, os_cmd,desc,ha){}

std::unique_ptr<std::string> Sys::Commands::ChdirCommand::RunWithArgs(const std::vector<std::string> args) const 
{

  const std::string path = args.front();

  const std::string current_path = std::filesystem::current_path();
  const std::string new_path = std::format("{0}/{1}",current_path, path);
  std::cout << "Path is: " << new_path << std::endl;

  if (chdir(new_path.c_str()) == 0) {
    std::cout << "Successfully changed directory to: " << path << std::endl;
  } else {
    if (errno == ENOENT) {
      throw std::runtime_error(strerror(errno));
    }
  }

  return nullptr;
}

std::unique_ptr<std::string>
Sys::Commands::ChdirCommand::Run() const 
{
  return nullptr;
}
