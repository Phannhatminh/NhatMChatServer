#include <iostream>
#include <string>
#include "user_handler.cpp"
#include "data_formater.cpp"

class Server {
private:
    UserHandler* userHandler;
    DataFormater* data_formater;
    Parser* parser;

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
    int handleLoginRequest() {
        return 0;
    }
public:
    Server() {
        std::cout << "Server created\n";
    }
    ~Server() {
        std::cout << "Server destroyed\n";
    }
    int listenForLogin() {
        data_formater->setMessageAvailableCallback(onLoginRequest);
        data_formater->onMessageAvailable();
    }
    int listenForMessage() {
        data_formater->setMessageAvailableCallback(onChatMessage);
        data_formater->listenForMessage();
    }
    static int onLoginRequest() {
        Server* server = new Server();
        return server -> listenForLogin();
    }
    static int onChatMessage() {
        Server* server = new Server();
        return server -> handleMessage(server->parse(new char[1]));
    }
};
