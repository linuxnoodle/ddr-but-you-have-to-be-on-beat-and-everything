#pragma once
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include "../include/game.hpp"

void parseKey(SDL_Keysym key, bool keyUpOrDown, void* ddr);
