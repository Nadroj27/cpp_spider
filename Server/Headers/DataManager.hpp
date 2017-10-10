/*
** DataManager.hpp for includes in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/server/includes
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Thu Sep 28 11:39:53 2017 Jeremy
** Last update Wed Oct 04 20:50:22 2017 Jeremy
*/

#ifndef __DATA_MANAGER_HPP__
#define __DATA_MANAGER_HPP__

#include  <iostream>
#include  <string>
#include  <regex>
#include  <fstream>
#include  <stdio.h>

class DataManager
{
  private:

  public:
    DataManager();
    ~DataManager();
    void mailParser(const std::string &filename);
    void phoneParser(const std::string &filename);
    void creditCardParser(const std::string &filename);
};

#endif /* !__DATA_MANAGER_HPP__ */
