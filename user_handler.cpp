#include <iostream>

class UserHandler {
private:
    UserHandler() {
        std::cout << "UserHandler created\n";
    }
    ~UserHandler() {
        std::cout << "UserHandler destroyed\n";
    }   
    UserHandler(const UserHandler&) = delete; // delete copy constructor
    UserHandler& operator=(const UserHandler&) = delete;
public:
    static UserHandler& getInstance() {
        static UserHandler instance;
        return instance;
    }
};


