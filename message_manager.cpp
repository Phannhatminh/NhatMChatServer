#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "data_formatter.cpp"

class MessageManager {
private:
    DataFormatter dataFormatter;
public:
    MessageManager() {
        std::cout << "MessageManager created" << std::endl;
    }
    std::map<int, Message*> getMessages() {
        return dataFormatter.getMessages();
    }
    bool hasMessages() {
        return dataFormatter.hasMessages();
    }
};