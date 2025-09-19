
void audioCallback(void *udata, Uint8 *stream, int len);

SDL_AudioSpec audio_init();

void walk(SDL_AudioSpec audio);

void level_start(SDL_AudioSpec audio);

void level_clear(SDL_AudioSpec audio);