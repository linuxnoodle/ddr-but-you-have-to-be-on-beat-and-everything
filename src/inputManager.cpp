#include "../include/inputManager.hpp"

// Yes, I know that taking in seemingly random parameters doesn't look good.
// Tried passing the whole game object, but that sent me into circular dependency hell, so this is the current solution.

// keyUpOrDown:
// false for down
// true for up
int parseKey(SDL_Keysym key, bool keyUpOrDown, std::vector<note> &notes, int screenHeight, bool (&activatedReceptors)[4]){
    if (!keyUpOrDown){
        bool justSent[] = {false, false, false, false};
        switch (key.sym){
            case SDLK_z:
            case SDLK_a:
                activatedReceptors[0] = true;
                justSent[0] = true;
                break;
            case SDLK_x:
            case SDLK_s:
                activatedReceptors[1] = true;
                justSent[1] = true;
                break;
            case SDLK_PERIOD:
            case SDLK_k:
                activatedReceptors[2] = true;
                justSent[2] = true;
                break;
            case SDLK_SLASH:
            case SDLK_l:
                activatedReceptors[3] = true;
                justSent[3] = true;
                break;
            case SDLK_ESCAPE:
                return 1; 
            case SDLK_RETURN:
                return 2;
            default:
                break;
        }
        for (unsigned long int i = 0; i < notes.size(); ++i){
            if (justSent[notes[i].channel] && activatedReceptors[notes[i].channel] && notes[i].distance > screenHeight * 0.85 && notes[i].distance < screenHeight * 0.95){
                notes[i].show = false;
            } 
        }
    } else {
        switch (key.sym){
            case SDLK_z:
            case SDLK_a:
                activatedReceptors[0] = false;                
                break;
            case SDLK_s:
            case SDLK_x:
                activatedReceptors[1] = false;                
                break;
            case SDLK_PERIOD:
            case SDLK_k:
                activatedReceptors[2] = false;                
                break;
            case SDLK_SLASH:
            case SDLK_l:
                activatedReceptors[3] = false;                
                break;
            default:
                break;
        }
        
    }
    return 0;
}
