#include "core/ControllerManager.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <string>

int main() {
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
    std::shared_ptr<ControllerManager> controllerManager = std::make_shared<ControllerManager>(gamepadCount, gamepads);
    std::vector<std::shared_ptr<Controller>> controllers = controllerManager->getControllers();
    std::cout << "Number of controllers connected: " << std::to_string(controllerManager->getControllerCount()) << "\n";
    for(const auto &c : controllers) {
        std::string name = c->getName();
        std::string id = c->getId();
        std::cout << "id: " << id << " name: " << name << "\n";
    }
    SDL_free(gamepads);
    SDL_Quit();
    return 0;
}
