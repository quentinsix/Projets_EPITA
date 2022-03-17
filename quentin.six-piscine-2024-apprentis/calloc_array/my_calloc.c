#include <stddef.h>
#include <stdlib.h>
//#include <stdio.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
        return NULL;
    int *tabl = (int *)malloc(size * sizeof(int));
    if (tabl == NULL)
        return NULL;
    for (size_t i = 0; i < size; i++)
    {
        tabl[i] = init;
    }
    return tabl;
}

/*
int main()
{
    int *new = my_calloc(-5, 5);
    if (new == NULL)
        printf("bonjour");
    return 0;
}
*/
