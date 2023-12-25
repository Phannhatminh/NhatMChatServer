#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "message_manager.cpp"

class UserManager {
private:
    std::map<std::string, int> users;
    std::map<std::string, std::vector<std::string> > userMessages;
public:
    UserManager() {
        std::cout << "UserManager created" << std::endl;
    }
    std::map<std::string, int> getUsers() {
        return users;
    }
    void addUser(std::string username, int socket) {
        users[username] = socket;
    }
};