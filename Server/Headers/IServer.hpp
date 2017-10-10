//
// IServer.hpp for  in /home/puccio_c/rendu/C++/cpp_spider/Server/Headers
//
// Made by Cyril Puccio
// Login   <cyril.puccio@epitech.eu>
//
// Started on  Fri Sep 29 16:40:36 2017 Cyril Puccio
// Last update Fri Sep 29 16:44:26 2017 Cyril Puccio
//

#ifndef           _ISERVER_HPP_
# define           _ISERVER_HPP_

#include  <iostream>
#include  <string>
#include  <stdio.h>

class IServer
{
public:
  virtual         ~IServer () {};

  virtual bool isConnected() = 0;
  virtual void Start() = 0;
  virtual void Stop() = 0;
  virtual void sendCmd(std::string) = 0;
  virtual void receive() = 0;
  virtual int getPort() = 0;
};

#endif		/* !_ISERVER_HPP_ */
