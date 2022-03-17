#include "int_vector_bubble_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    size_t tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    for (size_t i = 0; i < (vec.size - 1); i++)
    {
        for (size_t j = 0; j < (vec.size - i - 1); j++)
        {
            if (vec.data[j] > vec.data[j + 1])
            {
                vec = swap(vec, j, (j + 1));
            }
        }
    }
    return vec;
}
