/*
** IEvent.hpp for cpp_spider in cpp_spider\Client\Headers
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 11:43:32 2017 august_t
** Last update Sun Oct 08 22:42:51 2017 fagnol_r
*/

#ifndef _IEVENT_HPP_
#define _IEVENT_HPP_

// #define _WIN32_WINNT 0x0502
//
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <boost/thread.hpp>
#include <Windows.h>

class   IEvent {
public:
  void writeDataInFile();
  bool getSend();
  void setSend(bool);
  void init();
};

#endif /* !_IEVENT_HPP_ */
