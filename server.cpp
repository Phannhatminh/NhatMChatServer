#include <iostream>
#include <string>
#include "user_manager.cpp"

// class Server for handling all the messages
class Server {
private:
    UserManager userManager; // for handling all the users
    MessageManager messageManager; // for handling all the messages
    int send(int UserID, Message* message) { // for sending a message to a user
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
    int broadcastMessage(Message* message) { // for broadcasting a message to all users
        std::map<std::string, int> my_map = userManager.getUsers();
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            send(it->second, message);
        }
    }
    int start() {
        while(true) {
            if (messageManager.hasMessages()) { // if there are messages
                std::map<int, Message*> messages = messageManager.getMessages(); // get the messages
                for (int i = 0; i < messages.size(); i++) { // for each message
                    Message* msg = messages[i];
                    if (msg -> getType() == "chat_message") { // if it is a chat message
                        broadcastMessage(msg); // broadcast it
                    }
                    if (msg -> getType() == "login_message") { // if it is a login message
                        userManager.addUser(msg -> getSender(), msg -> getSenderID()); // add the user
                    }
                    std::cout << msg -> getContent() << std::endl;
                }
            }
        }
        return 0;
    }
};