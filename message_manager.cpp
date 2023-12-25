#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "data_formatter.cpp"

//class for managing messages
class MessageManager {
private:
    DataFormatter dataFormatter; // data formatter
public:
    MessageManager() {
        std::cout << "MessageManager created" << std::endl;
    }
    std::map<int, Message*> getMessages() {
        return dataFormatter.getMessages(); // get the messages
    }
    bool hasMessages() {
        return dataFormatter.hasMessages(); // check if there are messages
    } 
};