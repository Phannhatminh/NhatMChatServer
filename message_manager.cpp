#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "data_formatter.cpp"

class MessageManager {
public:
    MessageManager() {
        std::cout << "MessageManager created" << std::endl;
    }
    Message* getMessage() {
        return new Message("message", "test", "test_sender", 0);
    }
    bool hasMessages() {
        return true;
    }
};