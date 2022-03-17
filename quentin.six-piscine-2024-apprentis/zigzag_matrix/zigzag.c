#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>

int *zigzag(size_t n)
{
    int *tabl = (int *) calloc(n * n, sizeof(int));
    int index = 0;
    int nb = 1;
    for (size_t boucle1 = 0; boucle1 < n - 1; boucle1++)
    {

    }
    for (size_t i = 0; i < n * n; i++)
    {
        tabl[i] = i;
    }
    return tabl;
}

/* This function display a `matrix` of size `n` */
void print_matrix(const int *matrix, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            printf("%4d", matrix[i * n + j]);
        printf("\n");
    }
}

int main(void)
{
    printf("zigzag of size 3:\n");
    int *zig3 = zigzag(3);
    print_matrix(zig3, 3);
    free(zig3);

    printf("zigzag of size 5:\n");
    int *zig5 = zigzag(5);
    print_matrix(zig5, 5);
    free(zig5);

    return 0;
}

