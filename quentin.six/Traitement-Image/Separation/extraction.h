#ifndef EXTRACTION_H
#define EXTRACTION_H
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  size_t rows;
  size_t cols;
  double* val;
} Matrix;



Matrix* create_matrix(size_t line, size_t cols);

Matrix* img_matrix(SDL_Surface* image);

Matrix* resize_matrix(Matrix* matrix, size_t width, size_t height);

void file_write_mat(Matrix* matrix, size_t counter);
void print_matrix(Matrix* matrix);
void extract(SDL_Surface* img, int topline, int bottomline, int leftcol, 
int rightcol, size_t counter);


#endif
