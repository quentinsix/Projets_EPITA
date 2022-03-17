#include "int_vector_insert_sort.h"

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    size_t temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    int temp = 0, j = 0;
    size_t len = vec.size;
    for (size_t i = 1; i < len; i++)
    {
        temp = vec.data[i];
        j = i - 1;
        while (vec.data[j] > temp && j >= 0)
        {
            vec = swap(vec, (j + 1), j);
            j--;
        }
        vec.data[j + 1] = temp;
    }
    return vec;
}
