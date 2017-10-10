/*
** main.cpp for server in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/server/Src
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Fri Sep 29 14:52:52 2017 Jeremy
** Last update Sun Oct 08 23:04:02 2017 Jeremy
*/

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "Server.hpp"
#include "DataManager.hpp"

void logsParsing()
{
	DataManager parser;

	parser.mailParser("Logs.txt");
	parser.phoneParser("Logs.txt");
	parser.creditCardParser("Logs.txt");
}

int main(int ac, char **av)
{
	if (ac < 2)
    {
      std::cerr << "Usage ./Server [port]" << std::endl;
      return (0);
    }
  if (av[1] && strcmp(av[1], "--parse") == 0)
    {
      logsParsing();
      return (0);
    }
  if (av[1] && std::atoi(av[1]) < 1024)
    {
      std::cerr << "Port must be > 1023" << std::endl;
      return (0);
    }
  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), std::atoi(av[1]));
  direct::Server socket(endpoint);
  socket.run();
  std::cerr << "Enter exit to shutdown the server" << std::endl;
  std::string request;
  std::getline(std::cin, request);
  socket.stop();
}
