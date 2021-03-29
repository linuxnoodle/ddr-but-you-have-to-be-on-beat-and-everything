#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_stdinc.h>

#include "inputManager.hpp"
#include "mapManager.hpp"
#include "music.hpp"
#include "sceneManager.hpp"

class game {
    public:
        void init(const char* title, int x, int y, int width, int height, bool fullscreen);

        void handleEvents();
        void addEvent(Uint32 type);
        void update(int frameTime);
        void render();
        void clean();

        bool getIfRunning(){ return isRunning; };
        int getScreenWidth(){ return screenWidth; };
        int getScreenHeight(){ return screenHeight; };

        std::vector<note> currentNotes;
        static SDL_Event event;
        bool activatedReceptors[4];

    private:
        SDL_Texture *receptor;
        SDL_Window *window;
        SDL_Renderer *renderer;

        SDL_Rect destinationRect;
        
        bool isRunning;
        int screenWidth, screenHeight;
};
