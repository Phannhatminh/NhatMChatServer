#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "message_manager.cpp"

//class for managing users
//Layer 7
class UserManager { 
private:
    std::map<std::string, int> users; // username, ID
    std::map<std::string, std::vector<std::string> > userMessages; // username, messages
public:
    UserManager() { // constructor
        std::cout << "UserManager created" << std::endl;
    }
    std::map<std::string, int> getUsers() {
        return users;
    }
    void addUser(std::string username, int id) {
        users[username] = id; // add the user
    }
};