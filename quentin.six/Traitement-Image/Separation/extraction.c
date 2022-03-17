#include "extraction.h"
#include "../Init/getsetpixel.h"

//This function will create a matrix.
Matrix* create_matrix(size_t line, size_t cols) {
	Matrix* matrix = malloc(sizeof(Matrix));
	matrix->rows = line;
	matrix->cols = cols;

	matrix->val = calloc(line * cols, sizeof(double));

	return matrix;

}




//Not using it for now but will create a matrix of the image.
Matrix* img_matrix(SDL_Surface* img)
{

  size_t h = img->h;
  size_t w = img->w;
  Matrix* matrix = create_matrix(h, w);

  for (size_t i = 0; i < h; i++)
  {
    for (size_t j = 0; j < w; j++)
    {
      double value = get_value(img, j, i);
      matrix->val[i * w + j] = value;
    }
  }
  return matrix;
}


Matrix* resize_matrix(Matrix* matrix, size_t width, size_t height)
{
  Matrix* new_mat = create_matrix(height, width);

  double x_ratio = matrix->cols / (double) width;
  double y_ratio = matrix->rows / (double) height;
  double px, py;
  for (size_t i = 0; i < height; ++i)
  {
    for (size_t j = 0; j < width; ++j)
    {
      px = floor(j * x_ratio);
      py = floor(i * y_ratio);

      new_mat->val[(i * width) + j] = matrix->val[(size_t) ((py * matrix->cols) + px)];
    }
  }
  return new_mat;
}



//For first presentation, we are creating a file for each character to 
//show him.
void file_write_mat(Matrix* matrix, size_t counter)
{

	char str [12];
	sprintf(str, "%lu.txt", counter);
	
    	FILE* filemat = fopen(str, "w+");//Creating or opening the file.
	if(filemat != NULL) {
		


		//à voir pour la taille de la matrice
	        Matrix* new_mat = resize_matrix(matrix, 30, 30);	
		double *p = new_mat->val;
  		for (size_t r = 0; r < new_mat->rows; r++)
  		{
    			for (size_t c = 0; c < new_mat->cols; c++) {
      				if ((int) *p++ == 0)
        				fprintf(filemat, "0");
      				else
        				fprintf(filemat, "1");
    			}
			fprintf(filemat, "\n");
  		}
  		fprintf(filemat, "\n");







	} else {
		printf("Impossible");
	}
	fclose(filemat);

}

//Not using it.
void print_double(Matrix* matrix)
{
  double *p = matrix->val;
  for (size_t r = 0; r < matrix->rows; ++r)
  {
    for (size_t c = 0; c < matrix->cols; ++c)
      printf("%.2f ", *p++);
  }
  printf("\n");
}

//Main extract function.
void extract(SDL_Surface* img, int topline, int bottomline, int leftcol, 
		int rightcol, size_t counter)
{
	size_t height = bottomline - topline+1;//height of the matrix.
        size_t width = rightcol - leftcol + 1;//width of it.

  Matrix* matrix = create_matrix(height, width);

  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      matrix->val[i * width + j] = get_value(img, leftcol + j,
      			topline + i + 0);//We are putting the value in matrix.
    }
  }

  //print_double(matrix);
  file_write_mat(matrix, counter);
  free(matrix);
}


