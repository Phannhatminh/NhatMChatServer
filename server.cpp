#include <iostream>
#include <string>
#include "user_manager.cpp"
#include "message_manager.cpp"

class Server {
private:
    UserManager userManager;
    MessageManager messageManager;
    int send(int UserID, Message* message) {
        std::cout << "Sending message to user " << UserID << std::endl;
        return 0;
    }
public:
    Server() {
        std::cout << "Server created" << std::endl;
    }
    ~Server() {
        std::cout << "Server destroyed" << std::endl;
    }
    int broadcastMessage(Message* message) {
        std::map<std::string, int> my_map = userManager.getUsers();
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            send(it->second, message);
        }
    }
    int start() {
        while(true) {
            if (messageManager.hasMessages()) {
                Message* message = messageManager.getMessage();
                if (message -> getType() == "chat_message") {
                    broadcastMessage(message);
                }
                if (message -> getType() == "login_message") {
                    userManager.addUser(message -> getSender(), message -> getSenderID());
                }
                std::cout << message -> getContent() << std::endl;
            }
        }
        return 0;
    }
};