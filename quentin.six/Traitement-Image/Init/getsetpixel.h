#ifndef GETSET_H
#define GETSET_H

#include "chargnbimage.h"

Uint32 get_pixel(SDL_Surface* image, unsigned x, unsigned y);
void set_pixel(SDL_Surface* image, unsigned x, unsigned y, Uint32 pxl);
double get_value(SDL_Surface* image, size_t x, size_t y);

#endif
