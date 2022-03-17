#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void print_val(int value)
{
    if (value / 10 != 0)
        print_val(value / 10);
    putchar((value % 10) + '0');
}

void print_rec(size_t sizeh, const struct heap *h, size_t pos)
{
    if (pos <= sizeh - 1)
    {
        // int tmp = h->array[pos];
        if (pos != 0)
            putchar(' ');
        if (h->array[pos] < 0)
        {
            putchar('-');
            print_val(-h->array[pos]);
        }
        else
            print_val(h->array[pos]);
        print_rec(sizeh, h, pos * 2 + 1);
        print_rec(sizeh, h, pos * 2 + 2);
    }
}

void print_heap(const struct heap *heap)
{
    print_rec(heap->size, heap, 0);
    putchar('\n');
}
