#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
        return -1;
    size_t maxx = 0;
    for (size_t i = 0; i < vec.size; i++)
    {
        if (vec.data[i] < 0)
            return -1;

        if (vec.data[i] > vec.data[maxx])
            maxx = i;
    }
    size_t maxx_second = maxx;
    for (int i = maxx; i >= 0; i--)
    {
        if (vec.data[i] > vec.data[maxx_second])
            maxx_second = i;
    }
    for (size_t i = maxx; i < vec.size; i++)
    {
        if (vec.data[i] < 0 || vec.data[i] > vec.data[maxx_second])
            return -1;
        maxx_second = i;
    }
    return maxx;
}
