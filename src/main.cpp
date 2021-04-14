#include "../include/game.hpp"
#include "../include/music.hpp"

int main(){
    const int targetFPS = 144;
    const int frameDelay = 1000/targetFPS;
    
    const bool limitFPS = true;
    const bool debugMode = false;

    Uint32 frameStart;
    int frameTime = 0, framesFromStart = 0, frameTimeSum = 0;

    game ddr = game();
    ddr.init("DDRBYHTBOBAE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, true);
    
    while (ddr.getIfRunning()){
        frameStart = SDL_GetTicks();
        
        ddr.handleEvents(framesFromStart, (float)frameTimeSum/framesFromStart);
        ddr.update(frameTime);
        ddr.render();

        frameTime = SDL_GetTicks() - frameStart;
        
        // Delays time to get a frame rate cap of 144.
        if (limitFPS)
            SDL_Delay(frameDelay - ((frameDelay > frameTime) * frameTime));
        ++framesFromStart;
        frameTimeSum += frameTime;
    }

    ddr.clean();
    return 0;
}
