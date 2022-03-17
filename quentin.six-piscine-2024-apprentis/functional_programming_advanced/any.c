#include <stdio.h>

#include "functional_programming_advanced.h"

bool any(int *array, size_t len, bool (*func)(int))
{
    if (len == 0)
    {
        return false;
    }
    if (func(*array) == true)
    {
        return true;
    }
    return false || any(array + 1, len - 1, func);
}
