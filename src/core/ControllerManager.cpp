#include "ControllerManager.h"
#include <iostream>

ControllerManager::ControllerManager(std::string id, std::string name) : connectionId(id), name(name) {}

std::string ControllerManager::getId() const {
    return connectionId;
}
std::string ControllerManager::getName() const {
    return name;
}