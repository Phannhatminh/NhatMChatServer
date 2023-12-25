#include <iostream>
#include <string>
#include "server.cpp"

int main()
{
    Server server;
    std::cout << "Hello World!" << std::endl;
    server.start();
    return 0;
}