#include "../include/game.hpp"
#include "../include/music.hpp"

int main(){
    const int targetFPS = 144;
    const int frameDelay = 1000/targetFPS;

    Uint32 frameStart;
    int frameTime;

    game ddr = game();
    ddr.init("DDRBYHTBOBAE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
    
    while (ddr.getIfRunning()){
        frameStart = SDL_GetTicks();
        
        ddr.handleEvents();
        ddr.update();
        ddr.render();

        frameTime = SDL_GetTicks() - frameStart;

        // Delays time to get a frame rate cap of 144.
        SDL_Delay(frameDelay - ((frameDelay > frameTime) * frameTime));
    }

    ddr.clean();
    return 0;
}
