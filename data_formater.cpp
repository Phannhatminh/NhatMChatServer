#include <iostream>
#include "session_manager.cpp"

using CallbackFunction = int (*)();
class DataFormater {
private:
    CallbackFunction callback;
    SessionManager* session_manager;
    Parser* parser;
public:
    DataFormater() {
        std::cout << "DataFormater created\n";
    }
    ~DataFormater() {
        std::cout << "DataFormater destroyed\n";
    }
    Message* parse(char* buffer) {
        return parser->parse(buffer);
    }
    char* format(char* buffer) {
        return new char[1];
    }
    int send(char* buffer) {
        return session_manager->send(format(buffer));
    }
    void setMessageAvailableCallback(CallbackFunction cb) {
        callback = cb;
    }
    int onMessageAvailable() {
        if (session_manager->checkSession()) {
            callback();
        }
    }
};