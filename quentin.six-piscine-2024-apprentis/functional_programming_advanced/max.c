#include <stdio.h>

#include "functional_programming_advanced.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (len == 1)
        return array[len - 1];
    return func(foldl(array, len - 1, func), array[len - 1]);
}

int caca(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int max(int *array, size_t len)
{
    return foldl(array, len, caca);
}
