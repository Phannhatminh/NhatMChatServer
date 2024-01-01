#include <iostream>
#include <string>
#include "user_handler.cpp"
#include "data_formater.cpp"

class Server {
private:
    UserHandler* userHandler = &UserHandler::getInstance();
    DataFormater* data_formater = &DataFormater::getInstance();
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
    Server() {
        std::cout << "Server created\n";
    }
    ~Server() {
        std::cout << "Server destroyed\n";
    }
    // Make sure that there is at most one instance of Server
    Server(const Server&) = delete; // delete copy constructor
    Server& operator=(const Server&) = delete;
public:
    static Server& getInstance() {
        static Server instance;
        return instance;
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
        return Server::getInstance().handleLoginRequest();
    }
    static int onChatMessage() {
        return Server::getInstance().handleMessage(Server::getInstance().parse(new char[1]));
    }
};
