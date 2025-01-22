#include <iostream>
#include <thread>
#include "command.h"
#include "core.h"
#include <string>
#include <boost/algorithm/string.hpp>
#include "server.h"
using boost::asio::ip::tcp;


void gracefull_shutdown(int sig) {
  std::cout << "Shutting down server..." << std::endl;
}

int main(int argc, char **argv) {
  if(argc < 2)
  {
    std::cerr << "Please provide a port number" << std::endl;
    std::cerr << "E.g.: ./luspew-jailshell 4000" << std::endl;
    return -1;
  }

  int port = std::atoi(argv[1]); 

  boost::asio::io_context io_context;

  Server server(io_context,port);

  std::signal(SIGTERM, gracefull_shutdown);

  server.Run();

  return 0;
}

