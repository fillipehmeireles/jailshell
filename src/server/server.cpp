#include "server.h"
#include <boost/asio.hpp>
#include "client.h"
#include <string>
#include <iostream>
Server::Server(boost::asio::io_context& io_context, int port):
  io_context_(io_context),
  acceptor_(io_context_, tcp::endpoint(tcp::v4(), port )),
  port_(port){}


void HandleClient_(Sys::Client client)
{
  client.HandleConnection();
}

void Server::Stop()
{
  this->running_ = false;
  this->acceptor_.close();
  this->io_context_.stop();
}

void Server::Run()
{
  Sys::Core core;
  core.SetupBuiltin();
  try {
    std::cout << "[i] Server listening on port " << port_ << "..." << std::endl;
    while (running_) {
      tcp::socket socket(io_context_);
      acceptor_.accept(socket);
      Sys::Client client(core, std::move(socket));
      std::cout << "[i] New client connected: " 
        <<  client.addr_and_port
        << std::endl;
      std::thread(HandleClient_, std::move(client)).detach();
    }
  } catch (std::exception &e) {
    std::cerr << "[!] Server error: " << e.what() << std::endl;
  }
}
