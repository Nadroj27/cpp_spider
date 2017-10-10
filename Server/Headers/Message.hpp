/*
** Message.hpp for CPP in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/Server/Headers
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Sun Oct 08 23:22:48 2017 Jeremy
** Last update Sun Oct 08 23:22:51 2017 Jeremy
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace direct {

  class Message {

  public:
    enum { header_length = 4 };
    enum { max_body_length = 512 };

    Message() : body_length_(0)
    {
    }

    Message(const std::string &body) : body_length_(0)
    {
      std::memset(this->data(), '\0', header_length + max_body_length);
      this->body_length(std::strlen(body.c_str()));
      std::memcpy(this->body(), body.c_str(), this->body_length());
      this->encode_header();
    }

    const char* data() const {
      return data_;
    }

    char* data() {
      return data_;
    }

    std::size_t length() const {
      return header_length + body_length_;
    }

    const char* body() const {
      return data_ + header_length;
    }

    char* body() {
      return data_ + header_length;
    }

    std::size_t body_length() const {
      return body_length_;
    }

    void body_length(std::size_t new_length) {
      body_length_ = new_length;
      if (body_length_ > max_body_length)
        body_length_ = max_body_length;
    }

    bool decode_header() {
      char header[header_length + 1] = "";
      std::strncat(header, data_, header_length);
      body_length_ = std::atoi(header);
      if (body_length_ > max_body_length) {
        body_length_ = 0;
        return false;
      }
      return true;
    }

    void encode_header() {
      char header[header_length + 1] = "";
      std::sprintf(header, "%4d", static_cast<int>(body_length_));
      std::memcpy(data_, header, header_length);
    }

  private:
    char data_[header_length + max_body_length];
    std::size_t body_length_;

  };

}

#endif // MESSAGE_HPP_
