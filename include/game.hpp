#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include "../include/inputManager.hpp"

class game {
    public:
        void init(const char* title, int x, int y, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool isRunning;
        static SDL_Event event;

    private:
        SDL_Texture *receptor;
        SDL_Window *window;
        SDL_Renderer *renderer;

        SDL_Rect destinationRect;

};
