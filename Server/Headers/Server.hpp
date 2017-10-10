/*
** Server.hpp for CPP in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/Server/Headers
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Sun Oct 08 23:21:54 2017 Jeremy
** Last update Sun Oct 08 23:22:30 2017 Jeremy
*/

#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <map>
#include <memory>
#include <signal.h>
#include <utility>

#include "Connection.hpp"

namespace direct {

  class Server {

  public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    explicit Server(const boost::asio::ip::tcp::endpoint& endpoint);

    void run();
    void stop();

    void broadcast(const std::string &message);

  private:
    void do_accept();
    void do_await_stop();

    boost::asio::io_service _io_service;
    boost::asio::signal_set _signals;
    boost::thread _io_thread;
    boost::asio::ip::tcp::acceptor _acceptor;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::endpoint _endpoint;

    std::vector<std::shared_ptr<direct::Session> > _sessions;

  };

}

#endif // HTTP_SERVER_HPP
