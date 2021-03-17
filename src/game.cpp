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
    SDL_Surface *image = IMG_Load("noteskins/receptor.png");
    receptor = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

void game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            parseKey(event.key.keysym, false, this);
            break;
        case SDL_KEYUP:
            parseKey(event.key.keysym, true, this);
            break;
        default:
            break;
    }
}

void game::update(){
    destinationRect.h = 128;
    destinationRect.w = 128;
    destinationRect.x = 256;
    destinationRect.y = 512;
}

void game::render(){
    SDL_RenderClear(renderer);
    
    for (int i = 0; i < 4; ++i){    
        SDL_RenderCopy(renderer, receptor, NULL, &destinationRect);
        destinationRect.x += 213;
    }

    SDL_RenderPresent(renderer);
}

void game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
