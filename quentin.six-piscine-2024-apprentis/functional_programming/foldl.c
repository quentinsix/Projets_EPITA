#include <stdio.h>

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (len == 1)
        return array[len - 1];
    return func(foldl(array, len - 1, func), array[len - 1]);
}
