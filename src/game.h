#include <stdio.h>
#include <stdlib.h>
#include "include/SDL2/SDL_render.h"
#include "include/SDL2/SDL_rect.h"

void playUI();

void make_shadows(SDL_Renderer* renderer, SDL_Rect rect, char** labyrinth, int d, int x, int y);