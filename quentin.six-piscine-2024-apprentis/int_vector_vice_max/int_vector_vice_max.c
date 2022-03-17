#include "int_vector_vice_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int viceMax = vec.data[0];
    int tmp = 0;
    for (size_t i = 1; i < vec.size; i++)
    {
        tmp = vec.data[i];
        if (max < tmp)
            max = tmp;
    }
    if (max == vec.data[0])
        viceMax = vec.data[1];
    for (size_t i = 0; i < vec.size; i++)
    {
        tmp = vec.data[i];
        if (tmp < max && tmp > viceMax)
            viceMax = tmp;
    }
    return viceMax;
}
/*
int main()
{
    struct int_vector vec1 = {
        .size = 6,
        .data = { 0, 1, 2, 3, 4, 5 }
    };
    struct int_vector vec2 = {
        .size = 6,
        .data = { 0, 1, 2, 1, 1, 5 }
    };
    struct int_vector vec3 = {
        .size = 4,
        .data = { -2, -7, -55, -233}
    };
    printf("%d\n",int_vector_vice_max(vec1));
    printf("%d\n",int_vector_vice_max(vec2));
    printf("%d\n",int_vector_vice_max(vec3));
    return 0;
}
*/
