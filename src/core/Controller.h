#pragma once
#include <iostream>
class Controller {
private:
    const std::string name;
    const std::string id;
public:
    Controller(const std::string id, const std::string name);
    std::string getName();
    std::string getId(); 
    ~Controller() {
        std::cout << "Controller object destroyed: " << name << "\n";
    }
};
