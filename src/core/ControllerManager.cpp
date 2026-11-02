#include "ControllerManager.h"
#include "Controller.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <string>

ControllerManager::ControllerManager(int count, SDL_JoystickID *gamepads) : controllerCount(count){
    for(int i = 0; i < count; i++) {
        SDL_JoystickID id = gamepads[i];
        std::string controllerName = SDL_GetGamepadNameForID(id);
        std::string controllerID = std::to_string(id);
        std::shared_ptr<Controller> newController = std::make_shared<Controller>(controllerID, controllerName);
        controllers.push_back(newController);
    }
}

int ControllerManager::getControllerCount() {
    return controllerCount;
}
std::vector<std::shared_ptr<Controller>> ControllerManager::getControllers() {
    return controllers;
}