#include <iostream>
#include <map>
#include <string>
#include "parser.cpp"

class SessionManager {
private:
    CallbackFunction callback;
    std::map<std::string, int> sessions;
    Parser* parser;
    SessionManager() {
        std::cout << "SessionManager created\n";
    }
    ~SessionManager() {
        std::cout << "SessionManager destroyed\n";
    }
    // Make sure that there is at most one instance of SessionManager
    SessionManager(const SessionManager&) = delete; // delete copy constructor
    SessionManager& operator=(const SessionManager&) = delete;
public:
    static SessionManager& getInstance() {
        static SessionManager instance;
        return instance;
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
    int haveNoSession() {
        return callback();
    }
    void setCallback(CallbackFunction cb) {
        callback = cb;
    }
    int onRecieveMessage(char* buffer) {
        Message* message = parse(buffer);
        if (checkSession()) {
            callback(); //callback to the data_formater for the data_formater to handle the message's type.
            send(encode(message, buffer));
        }
    }
    int onLoginRequest(char* buffer) {
        Message* message = parse(buffer);
        if (checkSession()) {
            callback(); //callback to the data_formater for the dataformater to call to the server
            send(encode(message, buffer));
        }
    }
};