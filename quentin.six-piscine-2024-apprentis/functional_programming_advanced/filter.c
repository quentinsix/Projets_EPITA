#include <stdio.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    int i = 0;
    *out_array = malloc(len * sizeof(int));
    for (size_t j = 0; j < len; j++)
    {
        if (func(array[j]) == true)
        {
            (*out_array)[i] = array[j];
            i++;
        }
    }
    return i;
}
