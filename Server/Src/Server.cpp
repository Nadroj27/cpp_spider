/*
** Server.cpp for CPP in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/Server/Src
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Sun Oct 08 23:21:44 2017 Jeremy
** Last update Sun Oct 08 23:21:48 2017 Jeremy
*/

#include "Server.hpp"

direct::Server::Server(const boost::asio::ip::tcp::endpoint& endpoint)
: _io_service(), _signals(this->_io_service), _acceptor(this->_io_service, endpoint), _socket(this->_io_service), _endpoint(endpoint) {
  this->_signals.add(SIGINT);
  this->_signals.add(SIGTERM);
#if defined(SIGQUIT)
  this->_signals.add(SIGQUIT);
#endif

  do_await_stop();

  do_accept();
}

void direct::Server::run() {
  this->_io_thread = boost::thread(boost::bind(&boost::asio::io_service::run, &this->_io_service));
}

void direct::Server::stop() {
  this->_io_service.stop();
  this->_io_thread.join();
}

void direct::Server::broadcast(const std::string &message) {
  for (auto &session: this->_sessions) {
    session->deliver(message);
  }
}

void direct::Server::do_accept() {
  this->_acceptor.async_accept(this->_socket,
      [this](boost::system::error_code ec) {
        switch (ec.value() ) {
          case boost::system::errc::success: {
            this->_sessions.push_back(std::make_shared<direct::Session>(std::move(this->_socket)));
            this->_sessions.back()->start();
            break;
          }
          default: {

          }
          break;
        }

        do_accept();
      });
}

void direct::Server::do_await_stop() {
  this->_signals.async_wait(
      [this](boost::system::error_code, int) {
        this->_acceptor.close();
      });
}
