#include <stdio.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

void map(int *array, size_t len, void (*func)(int *))
{
    for (size_t i = 0; i < len; i++)
        func(array + i);
}

bool is_even(int val)
{
    return (val % 2) == 0;
}

void print(int *val)
{
    printf("%d\n", *val);
}

void print_even(int *array, size_t len)
{
    int *tab = NULL;
    size_t size = filter(array, len, &tab, is_even);
    if (size > 0)
        map(tab, size, print);
    free(tab);
}
