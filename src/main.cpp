#include <iostream>
#include <SDL3/SDL.h>

int main() {
    std::cout << "Controller Configurator started!\n";
    int version = SDL_GetVersion();
    std::cout << "SDL3 Version: " << SDL_VERSIONNUM_MAJOR(version) << "."
     << SDL_VERSIONNUM_MINOR(version) << "."
     << SDL_VERSIONNUM_MICRO(version);
    return 0;
}
