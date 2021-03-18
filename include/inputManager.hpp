#pragma once
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>

int parseKey(SDL_Keysym key, bool keyUpOrDown, bool (&receptorsActivated)[4]);
