#include <stddef.h>

int vmax(const int *const ptr, size_t size)
{
    int max = ptr[0];
    int tmp;
    int min = ptr[0];
    for (size_t i = 1; i < size; i++)
    {
        tmp = ptr[i];
        if (max < tmp)
            max = tmp;
    }
    for (size_t i = 1; i < size; i++)
    {
        tmp = ptr[i];
        if (min > tmp)
            min = tmp;
    }
    int viceMax = min;
    for (size_t i = 0; i < size; i++)
    {
        tmp = ptr[i];
        if (tmp < max && tmp > viceMax)
            viceMax = tmp;
    }
    return viceMax;
}
