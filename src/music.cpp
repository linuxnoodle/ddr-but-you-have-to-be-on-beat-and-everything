#include "../include/music.hpp"

Uint8 *wavBuffer;
SDL_AudioSpec wavSpec;
Uint32 wavLength;
SDL_AudioDeviceID deviceId;

void playSong(const char *songPath){
    SDL_LoadWAV(songPath, &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}

void pauseSong(){

}
