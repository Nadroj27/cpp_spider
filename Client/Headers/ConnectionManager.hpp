/*
** ConnectionManager.hpp for cpp_spider in E:\cpp_spider\Client\Headers
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 14:51:56 2017 august_t
** Last update	Mon Oct 02 16:03:27 2017 Sonny Fournier
*/

#ifndef _CONNECTIONMANAGER_HPP_
#define _CONNECTIONMANAGER_HPP_

#define _WIN32_WINNT 0x0502

class   ConnectionManager
{
protected:
  void  sendData();
  void  receiveServer();
  void  cryptData();
};

#endif /* !_CONNECTIONMANAGER_HPP_ */
