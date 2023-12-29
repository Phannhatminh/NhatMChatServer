#include <iostream>

class Message {
public:
    Message() {
        std::cout << "Message created\n";
    }
    ~Message() {
        std::cout << "Message destroyed\n";
    }
};
