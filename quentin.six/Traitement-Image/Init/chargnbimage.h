#ifndef IMAGE_H 
#define IMAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Surface* charg_img(char* path);
SDL_Window* disp_img(SDL_Surface* image);
void wait_for_keypressed();

#endif
