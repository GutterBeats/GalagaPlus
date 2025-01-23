//
// main.cpp
// Created by Anthony Lesch on 1/7/25
//

#define SDL_MAIN_HANDLED
#include <cstdlib>
#include <SDL3/SDL.h>

int main(int argc, const char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("Could not initialize SDL!: %s", SDL_GetError());
        exit(1);
    }

    atexit(SDL_Quit);

    SDL_Window* window;
    SDL_Renderer* renderer;

    const bool created = SDL_CreateWindowAndRenderer(
        "Galaga Plus", 800, 600, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer);

    if (!created || !window || !renderer) {
        SDL_Log("Could not create a window/renderer!: %s", SDL_GetError());
        exit(1);
    }

    bool isRunning = true;
    while (isRunning) {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }
}
