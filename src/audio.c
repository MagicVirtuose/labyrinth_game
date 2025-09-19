#include <stdio.h>
#include <string.h>
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_audio.h"
#include "audio.h"

SDL_AudioSpec audioBufferSpec;
Uint8  *audioBuffer = NULL;
Uint32 audioBufferLen;
Uint32 audioLen;
Uint32 audioPos;

void audioCallBack(void *udata, Uint8 *stream, int len){

    if (audioLen== 0){ return; }

    memset(stream,0,len);

    if (audioPos < audioBufferLen){
        if (audioPos+len > audioBufferLen){
            len = audioBufferLen = audioPos;
        }
        SDL_MixAudio(stream, audioBuffer+audioPos,len , SDL_MIX_MAXVOLUME);
        audioPos +=len;
    }

    audioLen-=len;

    SDL_PauseAudio(0);

    while(audioLen > 0){
        SDL_Delay(100);
    }

    SDL_CloseAudio();
}

SDL_AudioSpec audio_init(){

    SDL_AudioSpec audio;
    
    audio.freq = 22050;
    audio.format = AUDIO_S16;
    audio.channels = 1;
    audio.samples = 1024;
    audio.callback = audioCallBack;
    audio.userdata = NULL;

    if (SDL_OpenAudio(&audio, &audioBufferSpec) < 0){
        fprintf(stderr, "Erreur audio : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return audio;
}


void walk(SDL_AudioSpec audio){

    if (!SDL_LoadWAV("assets/sounds/walk.wav", &audioBufferSpec, &audioBuffer, &audioBufferLen) ){
        printf("Erreur de chargement du fichier wav.\n");
        exit(EXIT_FAILURE);
    }

    SDL_FreeWAV(audioBuffer);
}

void level_start(SDL_AudioSpec audio){

    if (!SDL_LoadWAV("assets/sounds/start.wav", &audioBufferSpec, &audioBuffer, &audioBufferLen) ){
        printf("Erreur de chargement du fichier wav.\n");
        exit(EXIT_FAILURE);
    }

    SDL_FreeWAV(audioBuffer);
}

void level_clear(SDL_AudioSpec audio){

    if (!SDL_LoadWAV("assets/sounds/clear.wav", &audioBufferSpec, &audioBuffer, &audioBufferLen) ){
        printf("Erreur de chargement du fichier wav.\n");
        exit(EXIT_FAILURE);
    }

    SDL_FreeWAV(audioBuffer);
}