#include <SDL2/SDL_video.h>
#include <iostream>

//#include "../include/music.hpp"
#include "../include/game.hpp"

int main(){
    game ddr = game();
    
    ddr.init("DDRBYHTBOBAE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
    
    while (ddr.running()){
        ddr.handleEvents();
        ddr.update();
        ddr.render();
    }

    ddr.clean();
    return 0;
}
