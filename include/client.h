#pragma once

#include <string> 
#include <boost/asio.hpp>
#include "core.h"


#define BUFFER_SIZE 1024 

using boost::asio::ip::tcp;

namespace Sys{
  class Client {
    public:
      Client(Sys::Core c, tcp::socket s);
      std::string addr_and_port;
      void HandleConnection();
    private:
      tcp::socket socket;
      Sys::Core core;
  };
}
