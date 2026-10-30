#include <iostream>
#include <SDL3/SDL.h>

int main() {
    //initialize the gamepad
    if (!SDL_Init(SDL_INIT_GAMEPAD)) {
        std::cerr << "SDL3 initialization failed." << SDL_GetError() << "\n";
        return 1;
    }
    std::cout << "SDL3 initialization successfully\n";
    int gamepadCount = 0;
    SDL_JoystickID *gamepads = SDL_GetJoysticks(&gamepadCount);

    if(!gamepads) {
        std::cerr << "Gamepads detection failed" << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    } else {
        std::cout << "Gamepads detected: " << gamepadCount << "\n";
    }
    for(int i = 0; i < gamepadCount; i++) {
        SDL_JoystickID id = gamepads[i];
        const char* name = SDL_GetJoystickNameForID(id);
        std::cout << "Device: " << name;
    }
    SDL_free(gamepads);
    SDL_Quit();
    return 0;
}
