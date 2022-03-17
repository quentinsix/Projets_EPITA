#include "mat_mult.h"
void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    int sum;
    int r1 = matrices_size[0];
    int r2 = matrices_size[1];
    int c2 = matrices_size[2];

    for (int x = 0; x < r1; x++)
    {
        for (int y = 0; y < c2; y++)
        {
            sum = 0;
            for (int z = 0; z < r2; z++)
            {
                sum += (*(*(mat1 + x) + z)) * (*(*(mat2 + z) + y));
            }
            *(*(out + x) + y) = sum;
        }
    }
}
