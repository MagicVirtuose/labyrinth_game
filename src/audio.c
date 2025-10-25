#include <stdio.h>
#include <string.h>
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_audio.h"
#include "include/SDL2/SDL_mixer.h"
#include "audio.h"

static Uint8* audio_pos;
static Uint32 audio_len;

void audioCallBack(void *udata, Uint8 *stream, int len){

    if (audio_len== 0){
        SDL_memset(stream, 0, len); 
        return; }

    int bytes_to_mix = len;

    if( bytes_to_mix > audio_len){
        bytes_to_mix = audio_len;
    }

    SDL_MixAudio(stream, audio_pos, bytes_to_mix , SDL_MIX_MAXVOLUME);

    if (len > bytes_to_mix){
        SDL_memset(stream + bytes_to_mix, 0, len - bytes_to_mix);
    }
    audio_pos +=bytes_to_mix;
    audio_len -=bytes_to_mix;
}

int audio_init(){

    if(SDL_Init(SDL_INIT_AUDIO) < 0){
        fprintf(stderr, "Erreur d'initialisation audio");
        return -1;
    }

    static Uint32 wav_length;
    static Uint8 *wav_buffer;
    static SDL_AudioSpec wav_spec;

    if (!SDL_LoadWAV("assets/sounds/clear.wav", &wav_spec, &wav_buffer, &wav_length) ){
        printf("Erreur de chargement du fichier wav.\n");
        exit(EXIT_FAILURE);
    }

    wav_spec.callback = audioCallBack;
    wav_spec.userdata = NULL;

    if(SDL_OpenAudio(&wav_spec, NULL) < 0){
        fprintf(stderr, "Erreur ouverture.");
        exit(-1);
    }

    SDL_PauseAudio(0);
    SDL_FreeWAV(wav_buffer);
    audio_pos = NULL;
    audio_len = 0;
}


void walk(){
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_Chunk* sound = Mix_LoadWAV("assets/sounds/walk.wav");
    if (sound == NULL){
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_VolumeChunk(sound, MIX_MAX_VOLUME);
    /* Play on any free channel and wait until it finishes before freeing/closing
       to avoid the sound being cut off immediately. */
    int channel = Mix_PlayChannel(-1, sound, 0);
    if (channel == -1){
        printf("Failed to play sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        while (Mix_Playing(channel)){
            SDL_Delay(50);
        }
    }

    Mix_FreeChunk(sound);
    sound = NULL;
    Mix_CloseAudio();
    Mix_Quit();
    
   
}

void level_start(){
        
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_Chunk* sound = Mix_LoadWAV("assets/sounds/start.wav");
    if (sound == NULL){
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_VolumeChunk(sound, MIX_MAX_VOLUME);
    /* Play on any free channel and wait until it finishes before freeing/closing
       to avoid the sound being cut off immediately. */
    int channel = Mix_PlayChannel(-1, sound, 0);
    if (channel == -1){
        printf("Failed to play sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    } else {
        while (Mix_Playing(channel)){
            SDL_Delay(50);
        }
    }

    Mix_FreeChunk(sound);
    sound = NULL;
    Mix_CloseAudio();
    Mix_Quit();
    printf("Sound played\n");
        
}

void level_clear(){
    printf("Level cleared sound\n");
}