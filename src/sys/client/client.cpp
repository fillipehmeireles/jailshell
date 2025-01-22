#include "client.h"
#include "core.h"
#include <string> 
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include "command_not_found_err.h"
#include <iostream>

using boost::asio::ip::tcp;

Sys::Client::Client(
    Sys::Core c,
    tcp::socket s
    ):core(c), 
  socket(std::move(s)){
    boost::asio::ip::tcp::endpoint remote_endpoint = socket.remote_endpoint();
    this->addr_and_port = std::format("{0}:{1}",remote_endpoint.address().to_string(), remote_endpoint.port());
  }

void Sys::Client::HandleConnection()
{
  try {
    while (true) {
      char data[BUFFER_SIZE];
      std::size_t cursor_size = 100;
      std::string cursor = std::format("{0} ~> ", addr_and_port);
      boost::asio::write(socket, boost::asio::buffer(cursor, cursor_size));

      std::size_t length = socket.read_some(boost::asio::buffer(data));
      std::string input = std::string(data, length);
      try { 
        boost::trim(input);
        Sys::Commands::Command cmd = core.GetSysCommand(input);
        std::string result = cmd.Run();
        boost::asio::write(socket, boost::asio::buffer(result, BUFFER_SIZE));
      }
      catch (const std::exception &e) {
        if (const Sys::Errors::CommandNotFoundException* cmd_not_found = dynamic_cast<const Sys::Errors::CommandNotFoundException*>(&e)) {
          std::cout << "[" << addr_and_port << "] " << cmd_not_found->what() << std::endl;
          std::string error_msg = std::format("{0}\n",e.what());
          boost::asio::write(socket, boost::asio::buffer(error_msg, BUFFER_SIZE));
        } else {
          std::cout << "[" << addr_and_port << "] " << e.what() << std::endl;
          std::string error_msg = std::format("Unexpected error: {0}\n",e.what());
          boost::asio::write(socket, boost::asio::buffer(error_msg, BUFFER_SIZE));
        }
        continue;
      }
    }
  } catch (std::exception &e) {
    if (const boost::system::system_error* asio_error = dynamic_cast<const boost::system::system_error*>(&e)) {
      if (asio_error->code() == boost::asio::error::eof) {
        std::cerr << "[i] Client disconnected gracefully." << std::endl;
      } else {
        std::cerr << "[!] Error: " << asio_error->code().message() << std::endl;
      }
    } else {
      std::cerr << "[!] Unexpected exception: " << e.what() << std::endl;
    }
  }
}
