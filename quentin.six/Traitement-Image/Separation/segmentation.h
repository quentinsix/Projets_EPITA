#ifndef SEGMENTATION_H
#define SEGMENTATION_H
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../Init/chargnbimage.h"
#include "../Init/getsetpixel.h"



void seg_hor(SDL_Surface* image);
int seg_ver(SDL_Surface* image,
                    size_t offset,
                    int startline,
                    int endline);



#endif
