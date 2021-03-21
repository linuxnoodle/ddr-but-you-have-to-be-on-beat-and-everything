#pragma once
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_stdinc.h>
#include <filesystem>

extern Uint8 *wavBuffer;
extern SDL_AudioSpec wavSpec;
extern Uint32 wavLength;
extern SDL_AudioDeviceID deviceId;

void playSong(const char *songPath);
void pauseSong();
