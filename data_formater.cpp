#include <iostream>
#include "session_manager.cpp"


class DataFormater {
private:
    CallbackFunction callback;
    SessionManager* session_manager = &SessionManager::getInstance();
    Parser* parser;
    Message* parse(char* buffer) {
        return parser->parse(buffer);
    }
    char* format(char* buffer) {
        return new char[1];
    }
    DataFormater() {
        std::cout << "DataFormater created\n";
    }
    ~DataFormater() {
        std::cout << "DataFormater destroyed\n";
    }
    // Make sure that there is at most one instance of DataFormater
    DataFormater(const DataFormater&) = delete; // delete copy constructor
    DataFormater& operator=(const DataFormater&) = delete;
public:
    static DataFormater& getInstance() {
        static DataFormater instance;
        return instance;
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
        if (DataFormater::getInstance().session_manager->checkSession()) {
            //parse the message
            DataFormater::getInstance().callback(); //a callback to the server
        }
    }
    static int onLoginRequest() {
        if (DataFormater::getInstance().session_manager->checkSession()) {
            DataFormater::getInstance().callback(); //a callback to the server
        }
    }
};