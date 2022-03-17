#include "recycler.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct recycler *recycler_create(size_t block_size, size_t total_size)
{
    if (block_size == 0 || total_size == 0)
        return NULL;

    if ((block_size % sizeof(size_t)) != 0)
        return NULL;

    if ((total_size % block_size) != 0)
        return NULL;
    struct recycler *recycler = malloc(total_size + sizeof(struct recycler));
    if (!recycler)
        return NULL;

    recycler->block_size = block_size;
    recycler->capacity = total_size / block_size;
    recycler->free = recycler; // + sizeof(struct recycler);
    recycler->chunk = recycler; // + sizeof(struct recycler);
    return recycler;
}

void recycler_destroy(struct recycler *r)
{
    if (r == NULL)
        return;
    //free(r->free);
    free(r);
}


void *recycler_allocate(struct recycler *r)
{
    if (r == NULL)
        return NULL;
    if (r->capacity == 0)
        return NULL;
    void *adress = r->free;
    r->capacity--;
    if (r->capacity == 0)
        r->free = NULL;
    return adress;
}

void recycler_free(struct recycler *r, void *block)
{
    if (r == NULL || r->free == NULL)
        return;
    r->free = block;
    r->capacity++;
}
