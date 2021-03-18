#include "../include/inputManager.hpp"
// keyUpOrDown:
// false for down
// true for up
int parseKey(SDL_Keysym key, bool keyUpOrDown, bool (&activatedReceptors)[4]){
    if (!keyUpOrDown){
        switch (key.sym){
            case SDLK_a:{
                activatedReceptors[0] = true;
                break;
            }
            case SDLK_s:{
                activatedReceptors[1] = true;
                break;
            }
            case SDLK_k:{
                activatedReceptors[2] = true;                
                break;
            }
            case SDLK_l:{
                activatedReceptors[3] = true;                
                break;
            }
            case SDLK_ESCAPE:{
                return 1; 
                break;
            }
            default:{
                break;
            }
        }
    } else {
        switch (key.sym){
            case SDLK_a:{
                activatedReceptors[0] = false;                
                break;
            }
            case SDLK_s:{
                activatedReceptors[1] = false;                
                break;
            }
            case SDLK_k:{
                activatedReceptors[2] = false;                
                break;
            }
            case SDLK_l:{
                activatedReceptors[3] = false;                
                break;
            }
            default:{
                break;
            }
        }
        
    }
    return 0;
}
