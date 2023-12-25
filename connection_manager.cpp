#include <iostream>
#include <string>
#include <map>
#include <vector>

//class for managing connections
class ConnectionManager {
public:
    ConnectionManager() {
        std::cout << "ConnectionManager created" << std::endl;
    }
    void connect() {
        std::cout << "ConnectionManager connected" << std::endl;
    }
    void disconnect() {
        std::cout << "ConnectionManager disconnected" << std::endl;
    }
    bool hasMessages() {
        return false;
    }
    char* getMessage() {
        return "";
    }
};