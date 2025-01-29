#include <iostream> 
#include <vector>
#include <string> 
#include <sstream> 
#include <boost/algorithm/string.hpp>
#include "command_utils.h"
std::vector<std::string> Utils::CommandUtils::PrepareArgsFromInput(std::string input)
{
  std::vector<std::string> args;

  std::istringstream stream(input);

  std::string command;
  stream >> command;  

  std::string remaining;
  std::getline(stream, remaining);  

  boost::trim(remaining);
  args.push_back(remaining);

  return args;
}
