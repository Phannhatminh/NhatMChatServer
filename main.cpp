#include <iostream>
#include <string>
#include "server.cpp"

int main() {
    std::string s = "Hello";   
    Server& server = Server::getInstance();
    std::cout << "Hello, World!\n";
    return 0;
}

// Next task: make all the component singleton and run the server