/*
** Connection.cpp for CPP in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/Server/Src
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Sun Oct 08 18:14:19 2017 Jeremy
** Last update Sun Oct 08 23:09:58 2017 Jeremy
*/

#include "Connection.hpp"

direct::Session::Session(boost::asio::ip::tcp::socket socket) : _socket(std::move(socket)) {
if (!(std::ifstream("Logs.txt")))
  std::ofstream logFile("Logs.txt");
}

void direct::Session::start() {
  do_read_header();
}

void direct::Session::deliver(const direct::Message& msg) {
  bool write_in_progress = !this->_write_msgs.empty();
  this->_write_msgs.push_back(msg);
  if (!write_in_progress) {
    do_write();
  }
}

void direct::Session::do_read_header() {
  auto self(shared_from_this());
  std::memset(this->_read_msg.data(), '\0', direct::Message::header_length + direct::Message::max_body_length);
  boost::asio::async_read(this->_socket, boost::asio::buffer(this->_read_msg.data(), direct::Message::header_length),
      [this, self](boost::system::error_code ec, std::size_t /*length*/) {
        if (!ec && this->_read_msg.decode_header()) {
          do_read_body();
        } else {
          //TODO ERROR
        }
      });
}

void direct::Session::do_read_body() {
  std::ofstream logFile;
  auto self(shared_from_this());
  boost::asio::async_read(this->_socket, boost::asio::buffer(this->_read_msg.body(), this->_read_msg.body_length()),
      [this, self](boost::system::error_code ec, std::size_t /*length*/) {
        if (!ec) {
        std::cout << "received: " << this->_read_msg.body() << std::endl;
          Message output("OK !");
          std::cout << "sending : " << output.body() << std::endl << std::endl;
          this->deliver(output);
          do_read_header();
        } else {
            //TODO ERROR
        }
      });
      logFile.open("Logs.txt", std::ios_base::app);
      logFile << this->_read_msg.body() << std::endl;
      logFile.close();
}

void direct::Session::do_write() {
  auto self(shared_from_this());
  boost::asio::async_write(this->_socket, boost::asio::buffer(this->_write_msgs.front().data(), this->_write_msgs.front().length()),
      [this, self](boost::system::error_code ec, std::size_t /*length*/) {
        if (!ec) {
          this->_write_msgs.pop_front();
          if (!this->_write_msgs.empty()) {
            do_write();
          }
        } else {
          //TODO ERROR
        }
      });
}
