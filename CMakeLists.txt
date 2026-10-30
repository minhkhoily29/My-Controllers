
cmake_minimum_required(VERSION 3.20)

project(MyControllers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch SDL3 from GitHub
include(FetchContent)

# Build SDL3 as a static library
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.18
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SDL3)

# Create our application
add_executable(MyControllers
    src/main.cpp
)

# Link SDL3 to our application
target_link_libraries(MyControllers PRIVATE SDL3::SDL3)
