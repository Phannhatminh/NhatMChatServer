#include <iostream>
#include <string>
#include "user_handler.cpp"
#include "data_formater.cpp"

class Server {
private:
    UserHandler* userHandler;
    DataFormater* data_formater;
    Parser* parser;
public:
    Server() {
        std::cout << "Server created\n";
    }
    ~Server() {
        std::cout << "Server destroyed\n";
    }
    using CallbackFunction = void (Server::*)();
    int send(Message* message) {
        return data_formater->send(encode(message));
    }
    Message* parse(char* buffer) {
        return parser->parse(buffer);
    }
    char* encode(Message* message) {
        return new char[1];
    }
    int handleMessage(Message* message) {
        return 0;
    }
    int listenForLogin() {
        data_formater->setMessageAvailableCallback(onLoginRequest);
        data_formater->onMessageAvailable();
    }
    static int onLoginRequest() {
        std::cout << "onLoginRequest\n";
        return 0;
    }
    static int onChatMessage() {
        return 0;
    }
};
