#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "message.cpp"
#include "connection_manager.cpp"

class DataFormatter {
private:
    std::map<int, Message*> messages;
    ConnectionManager connectionManager;

    void parseMessage(char* message) {
        std::string content = "";
        std::string type = "";
        std::string sender = "";
        int senderID = 0;
        int index = 0;
        while (message[index] != '\0') {
            if (message[index] == '|') {
                index++;
                break;
            }
            content += message[index];
            index++;
        }
        while (message[index] != '\0') {
            if (message[index] == '|') {
                index++;
                break;
            }
            type += message[index];
            index++;
        }
        while (message[index] != '\0') {
            if (message[index] == '|') {
                index++;
                break;
            }
            sender += message[index];
            index++;
        }
        while (message[index] != '\0') {
            if (message[index] == '|') {
                index++;
                break;
            }
            senderID *= 10;
            senderID += message[index] - '0';
            index++;
        }
        Message* newMessage = new Message(content, type, sender, senderID);
        addMessage(newMessage);
    }

public:
    DataFormatter() {
        std::cout << "DataFormatter created" << std::endl;
    }
    std::map<int, Message*> getMessages() {
        if (messages.size() == 0) {
            char* msg = connectionManager.getMessage();
            if (msg != NULL) {
                parseMessage(msg);
            }
        }
        return messages;
    }
    void addMessage(Message* message) {
        messages[messages.size()] = message;
    }
    bool hasMessages() {
        if(messages.size() > 0) {
            return true;
        }
        return connectionManager.hasMessages();
    }
};