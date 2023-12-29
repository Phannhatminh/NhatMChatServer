#include <iostream>
#include <string>
#include "message.cpp"

class Parser {
public:
    Parser() {
        std::cout << "Parser created\n";
    }
    ~Parser() {
        std::cout << "Parser destroyed\n";
    }
    Message* parse(char* buffer) {
        return new Message();
    }
};