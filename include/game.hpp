#pragma once
#include <SDL2/SDL.h>

class game {
    public:
        void init(const char* title, int x, int y, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; };

    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};
