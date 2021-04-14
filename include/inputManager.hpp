#pragma once
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <vector>

#include "mapManager.hpp"

int parseKey(SDL_Keysym key, bool keyUpOrDown, std::vector<note> &notes, int screenHeight, bool (&receptorsActivated)[4]);
