#include "../include/game.hpp"

void game::init(const char* title, int x, int y, int width, int height, bool fullscreen){
    int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0; 
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        // Initializes renderer, window
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        }

        screenHeight = height;
        screenWidth = width;
        
        loadMapFiles();
        mapList[0].initializeNotes();
        currentNotes = mapList[0].getNotes();
        
        // Plays song of first map
        if (mapList.size() > 0){    
            playSong(mapList[0].getSongPath().c_str());
        }

        // Loads images
        SDL_Surface *image = IMG_Load("noteskins/receptor.png");
        receptor = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);

        destinationRect.x = 2 * (screenWidth * 0.125);
        destinationRect.y = screenHeight * 0.9;
        destinationRect.h = 128;
        destinationRect.x = 128;
        
        isRunning = true;
    } else {
        SDL_Log("Failed to initialize.");
        isRunning = false;
    }
}

void game::addEvent(Uint32 type){
    SDL_Event event;
    event.type = type;
    SDL_PushEvent(&event);
}

void game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    // Hands off keyboard handling to inputManager
    switch (event.type){
        case SDL_QUIT:{
            isRunning = false;
            break;
        }
        case SDL_KEYDOWN:{
            int shouldQuit = parseKey(event.key.keysym, false, currentNotes, screenHeight, activatedReceptors);
            switch (shouldQuit){
                case 1:
                    isRunning = false;
                    break;
                case 2:
                    isInMap = true;
                    break;
            }
            break;
        }
        case SDL_KEYUP:{
            parseKey(event.key.keysym, true, currentNotes, screenHeight, activatedReceptors);
            break;
        }
        default:{
            break;
        }
    }
}

void game::update(int frameTime){
    if (!isInMap) return;
    for (long unsigned int i = 0; i < currentNotes.size(); ++i){
        currentNotes[i].distance += frameTime * 1;
    }
}

void game::render(){
    if (isInMap){
        for (long unsigned int i = 0; i < currentNotes.size(); ++i){
            if (currentNotes[i].show){
                SDL_Rect rect = SDL_Rect{static_cast<int>(screenWidth * 0.363 + (135 * currentNotes[i].channel)), static_cast<int>(currentNotes[i].distance), 128, static_cast<int>(currentNotes[i].length)};
                SDL_SetRenderDrawColor(renderer, 10, 10, 20, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        
        SDL_RenderPresent(renderer);
        
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);
        // Draws receptors
        for (int i = 0; i < 4; ++i){    
            if (activatedReceptors[i]){
                destinationRect.h = 100;
                destinationRect.w = 100;
                destinationRect.x = screenWidth * 0.373 + (135 * i);
                destinationRect.y = screenHeight * 0.865;
            } else {
                destinationRect.h = 128;
                destinationRect.w = 128;
                destinationRect.x = screenWidth * 0.365 + (135 * i);
                destinationRect.y = screenHeight * 0.85;
            }
            SDL_RenderCopy(renderer, receptor, NULL, &destinationRect);
        }
    } else {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderPresent(renderer);
    }
}

void game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
}
