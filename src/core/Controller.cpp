#include "Controller.h"
#include <iostream>

Controller::Controller(const std::string id, const std::string name) : id(id), name(name) {}

std::string Controller::getName() {
    return name;
}

std::string Controller::getId() {
    return id;
}