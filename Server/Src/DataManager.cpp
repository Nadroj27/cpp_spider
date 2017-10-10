/*
** DataManager.cpp for Epitech in /Users/Jeremy/Documents/Epitech/CPP/cpp_spider/Server/Src
**
** Made by Jeremy
** Login   <Jeremy@epitech.net>
**
** Started on  Mon Oct 02 15:08:40 2017 Jeremy
** Last update Sun Oct 08 15:58:12 2017 Jeremy
*/

#include "DataManager.hpp"

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::mailParser(const std::string &filename)
{
  std::regex exp ("[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+.[a-zA-Z]+");
  std::smatch match;
  std::string str;
  std::ifstream file(filename);

  if (file)
    {
      while (std::getline(file, str))
        {
          while (std::regex_search(str, match, exp))
            {
              for (std::smatch::iterator x = match.begin(); x != match.end(); ++x)
                  std::cout << *x << std::endl;
              str = match.suffix().str();
            }
        }
    }
}

void DataManager::phoneParser(const std::string &filename)
{
  std::regex exp ("0[0-9][ ]?[0-9][0-9][ ]?[0-9][0-9][ ]?[0-9][0-9][ ]?[0-9][0-9]");
  std::smatch match;
  std::string str;
  std::ifstream file(filename);
  if (file)
    {
        while (std::getline(file, str))
        {
            while (std::regex_search(str, match, exp))
            {
                for (std::smatch::iterator x = match.begin(); x != match.end(); ++x)
                    std::cout << *x << std::endl;
                str = match.suffix().str();
            }
        }
    }
}

void DataManager::creditCardParser(const std::string &filename)
{
  std::regex exp ("([0-9]{4}[- ]?){3}[0-9]{4}");
  std::smatch match;
  std::string str;
  std::ifstream file(filename);

  if (file)
    {
      while (std::getline(file, str))
        {
          while (std::regex_search(str, match, exp))
            {
              for (std::smatch::iterator x = match.begin(); x != match.end(); ++x)
                  std::cout << *x << std::endl;
              str = match.suffix().str();
            }
        }
    }
}
