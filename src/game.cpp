#include "../include/game.hpp"

void game::init(const char* title, int x, int y, int width, int height, bool fullscreen){
    int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0; 
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
}

void game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void game::update(){
    
}

void game::render(){
    SDL_RenderClear(renderer);
    //TODO: add everything needed to render
    SDL_RenderPresent(renderer);
}

void game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
