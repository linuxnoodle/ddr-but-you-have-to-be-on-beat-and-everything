#include "../include/game.hpp"
#include "../include/music.hpp"

int main(){
    const int targetFPS = 144;
    const bool limitFPS = true;
    const int frameDelay = 1000/targetFPS;

    Uint32 frameStart;
    int frameTime = 0;

    game ddr = game();
    ddr.init("DDRBYHTBOBAE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);
    
    while (ddr.getIfRunning()){
        frameStart = SDL_GetTicks();
        
        ddr.handleEvents();
        ddr.update(frameTime);
        ddr.render();

        frameTime = SDL_GetTicks() - frameStart;

        // Delays time to get a frame rate cap of 144.
        if (limitFPS)
            SDL_Delay(frameDelay - ((frameDelay > frameTime) * frameTime));
    }

    ddr.clean();
    return 0;
}
