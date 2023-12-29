#include <iostream>

class UserHandler {
public:
    UserHandler() {
        std::cout << "UserHandler created\n";
    }
    ~UserHandler() {
        std::cout << "UserHandler destroyed\n";
    }
};


