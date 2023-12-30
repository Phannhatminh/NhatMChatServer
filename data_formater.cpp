#include <iostream>
#include "session_manager.cpp"


class DataFormater {
private:
    CallbackFunction callback;
    SessionManager* session_manager;
    Parser* parser;
    Message* parse(char* buffer) {
        return parser->parse(buffer);
    }
    char* format(char* buffer) {
        return new char[1];
    }
public:
    DataFormater() {
        std::cout << "DataFormater created\n";
    }
    ~DataFormater() {
        std::cout << "DataFormater destroyed\n";
    }
    int send(char* buffer) {
        return session_manager->send(format(buffer));
    }
    void setMessageAvailableCallback(CallbackFunction cb) {
        callback = cb;
    }
    int listenForMessage() {
        session_manager->setCallback(onMessageAvailable);
        session_manager->haveNoSession();
    }
    int listenForLogin() {
        session_manager->setCallback(onLoginRequest);
        session_manager->haveNoSession();
    }
    static int onMessageAvailable() {
        DataFormater* data_formater = new DataFormater();
        if (data_formater->session_manager->checkSession()) {
            //parse the message
            data_formater->callback(); //a callback to the server
        }
    }
    static int onLoginRequest() {
        DataFormater* data_formater = new DataFormater();
        if (data_formater->session_manager->checkSession()) {
            data_formater->callback(); //a callback to the server
        }
    }
};