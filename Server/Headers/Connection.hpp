/*
** Connection.hpp for cpp_spider in /Users/Vacca_J/Desktop/cpp_spider/cpp_spider/Server/Headers
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat Sep 30 12:22:02 2017 Vacca_J
** Last update Sun Oct 08 23:22:24 2017 Jeremy
*/

#ifndef SESSION_HPP_
#define SESSION_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <boost/asio.hpp>
#include <cstdlib>
#include <deque>
#include <list>
#include <memory>
#include <set>
#include <utility>

#include "Message.hpp"

namespace direct {

  typedef std::deque<direct::Message> MessageQueue;

  class Session : public std::enable_shared_from_this<Session> {

  public:
    Session(boost::asio::ip::tcp::socket socket);

    void start();
    void deliver(const direct::Message& msg);

  private:
    void do_read_header();
    void do_read_body();
    void do_write();

    boost::asio::ip::tcp::socket _socket;
    direct::Message _read_msg;
    MessageQueue _write_msgs;
  };

}

#endif // SESSION_HPP_
