#include <iostream>
#include <string>
#include <map>
#include <vector>


class Message {
private:
    std::string content;
    std::string type;
    std::string sender;
    int senderID;
public:
    Message(std::string content, std::string type, std::string sender, int senderID) {
        this->content = content;
        this->type = type;
        this->sender = sender;
        this->senderID = senderID;
    }
    std::string getContent() {
        return this->content;
    }
    std::string getType() {
        return this->type;
    }
    std::string getSender() {
        return this->sender;
    }
    int getSenderID() {
        return this->senderID;
    }
};