#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *create = malloc(sizeof(struct heap));
    int *tab = malloc(8 * sizeof(int));
    if (!create || !tab)
        return NULL;
    create->size = 0;
    create->array = tab;
    create->capacity = 8;
    return create;
}
