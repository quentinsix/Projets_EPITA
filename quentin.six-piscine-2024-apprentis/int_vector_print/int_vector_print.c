#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    printf("%d", vec.data[0]);
    for (size_t i = 1; i < vec.size; i++)
        printf(" %d", vec.data[i]);
    printf("\n");
}
