#ifndef COLORBW_H
#define COLORBW_H

#include <stdlib.h>
#include <err.h>




void grayscale(SDL_Surface* image);
void black_white(SDL_Surface* image);
void noise(SDL_Surface *img);
void otsu(SDL_Surface *img);
SDL_Surface* Resize(SDL_Surface *img, float scalex, float scaley);
#endif
