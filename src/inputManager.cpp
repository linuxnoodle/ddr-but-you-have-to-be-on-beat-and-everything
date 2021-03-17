#include "../include/inputManager.hpp"

// keyUpOrDown:
// false for down
// true for up
void parseKey(SDL_Keysym key, bool keyUpOrDown, void* Game){
    // garbage hack I have to do to get around circular dependency
    // could most likely do better, but that's for later
    game* ddr = (game*)Game;
    if (keyUpOrDown){
        switch (key.sym){
            case SDLK_a:
                                
                break;
            case SDLK_s:
                
                break;
            case SDLK_k:
                
                break;
            case SDLK_l:
                
                break;
            case SDLK_ESCAPE:
                ddr->isRunning = false;
                break;
            default:
                break;
        }
    } else {
        switch (key.sym){
            case SDLK_a:
                
                break;
            case SDLK_s:
                
                break;
            case SDLK_k:
                
                break;
            case SDLK_l:
                
                break;
            default:
                break;
        }
        
    }
}
