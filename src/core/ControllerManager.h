#pragma once
#include "Controller.h"
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
class ControllerManager {
private:
    std::vector<std::shared_ptr<Controller>> controllers;
    int controllerCount;
public:
    ControllerManager(int count, SDL_JoystickID *gamepads);
    int getControllerCount();
    std::vector<std::shared_ptr<Controller>> getControllers();
    ~ControllerManager() {
        std::cout << "Controller Manager object destroyed" << "\n";
    }
};