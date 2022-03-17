#include <stdio.h>

#include "functional_programming_advanced.h"

bool all(int *array, size_t len, bool (*func)(int))
{
    if (len == 0)
    {
        return true;
    }
    if (func(*array) == false)
    {
        return false;
    }
    // return true && all(array + 1, len - 1, func);
    return true && all(array + 1, len - 1, func);
}
