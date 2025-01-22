#pragma once
#include <boost/asio.hpp>
#include "client.h"
#include <string>


class Server {
  public:
    Server(boost::asio::io_context& io_context,int port);
    void Run();
    void Stop();
  private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    bool running_ = true; 
    int port_;
};



