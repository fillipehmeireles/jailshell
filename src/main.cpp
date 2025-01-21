#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include "client.h"
#include "command.h"
#include "core.h"
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using boost::asio::ip::tcp;

#define BUFFER_SIZE 1024 

void handle_client(tcp::socket socket, Client client) {
  // TODO: Create Server layer (Control and Server)
  Sys::Core core;
  core.SetupBuiltin();
  try {
    while (true) {
      char data[BUFFER_SIZE];
      std::size_t cursor_size = 100;
      std::string cursor = std::format("{0} ~> ", client.addr_and_port);
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
        // TODO: Check the exception type
        std::string error_msg = std::format("{0}\n",e.what());
        boost::asio::write(socket, boost::asio::buffer(error_msg, BUFFER_SIZE));
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

int main(int argc, char **argv) {
  if(argc < 2)
  {
    std::cerr << "Please provide a port number" << std::endl;
    std::cerr << "E.g.: ./luspew-jailshell 4000" << std::endl;
    return -1;
  }
  int port = std::atoi(argv[1]); 
  try {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port ));

    std::cout << "[i] Server listening on port " << port << "..." << std::endl;

    while (true) {
      tcp::socket socket(io_context);
      acceptor.accept(socket);
      boost::asio::ip::tcp::endpoint remote_endpoint = socket.remote_endpoint();
      Client client(std::format("{0}:{1}",remote_endpoint.address().to_string(), remote_endpoint.port()));
      std::cout << "[i] New client connected: " 
        <<  client.addr_and_port
        << std::endl;
      std::thread(handle_client, std::move(socket), std::move(client)).detach();
    }
  } catch (std::exception &e) {
    std::cerr << "[!] Server error: " << e.what() << std::endl;
    return -1;
  }

  // TODO: Gracefull shutdown

  return 0;
}

