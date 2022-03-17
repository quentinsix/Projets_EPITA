#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void add(struct heap *heap, int val)
{
    if (heap != NULL)
    {
        if (heap->size == heap->capacity)
        {
            int *new_arr =
                realloc(heap->array, ((heap->capacity) + 3) * sizeof(int));
            if (new_arr != NULL)
            {
                heap->array = new_arr;
                heap->capacity += 3;
            }
        }
        size_t i = heap->size;
        heap->array[i] = val;
        size_t a = (i - 1) / 2;
        while (i != 0 && heap->array[i] > heap->array[a])
        {
            int tmp = heap->array[a];
            heap->array[a] = heap->array[i];
            heap->array[i] = tmp;
            i = a;
            a = (i - 1) / 2;
        }
        heap->size++;
    }
}
