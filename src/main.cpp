#include "core/ControllerManager.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <memory>
#include <vector>

int main() {
    std::vector<std::shared_ptr<ControllerManager>> connectedControllers;
    //initialize the gamepad
    if (!SDL_Init(SDL_INIT_GAMEPAD)) {
        std::cerr << "SDL3 initialization failed." << SDL_GetError() << "\n";
        return 1;
    }
    std::cout << "SDL3 initialization successfully\n";
    int gamepadCount = 0;
    SDL_JoystickID *gamepads = SDL_GetGamepads(&gamepadCount);
    //checking if we detected any gamepads
    if(!gamepads) {
        std::cerr << "Gamepads detection failed" << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }
    for(int i = 0; i < gamepadCount; i++) {
        SDL_JoystickID id = gamepads[i];
        std::string name = SDL_GetGamepadNameForID(id);
        std::string controllerId = std::to_string(id);
        std::shared_ptr<ControllerManager> newController = std::make_shared<ControllerManager>(
            new ControllerManager(controllerId, name));
        connectedControllers.push_back(newController);
    }
    for(auto c : connectedControllers) {
        std::cout << c->getId() << c->getName();
    }
    SDL_free(gamepads);
    SDL_Quit();
    return 0;
}
