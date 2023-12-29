#include <iostream>
#include <map>
#include <string>
#include "parser.cpp"

class SessionManager {
private:
    std::map<std::string, int> sessions;
    Parser* parser;
public:
    SessionManager() {
        std::cout << "SessionManager created\n";
    }
    ~SessionManager() {
        std::cout << "SessionManager destroyed\n";
    }
    int createSession() {
        return 0;
    }
    Message* parse(char* buffer) {
        return parser->parse(buffer);
    }
    char* encode (Message* message, char* buffer) {
        return new char[1];
    }
    int send(char* buffer) {
        return 0;
    }
    bool checkSession() {
        return true;
    }
    int haveNoSession(int (*callback)(int (*callback)()), int (*back)()) {
        return callback(back);
    }
};