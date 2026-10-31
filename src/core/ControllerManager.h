#pragma once
#include <string>

class ControllerManager {
private:
    static int counter;
    std::string connectionId;
    std::string name;
public:
    ControllerManager(std::string id, std::string name);
    std::string getId() const;
    std::string getName() const;
};