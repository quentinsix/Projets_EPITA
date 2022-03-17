#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap_value(int *array, size_t parent, size_t child)
{
    int tmp = array[parent];
    array[parent] = array[child];
    array[child] = tmp;
}

/*
void heapify_pop(struct heap *heap, size_t size, int *array)
{
    if (size == heap->size / 2 - 1)
        return;
    if (size * 2 + 1 <= size - 1)
    {
        if (array[size] < array[size * 2 + 1])
            swap_value(array, size, size * 2 + 1);
    }
    else if (size * 2 + 2 <= size - 1)
    {
        if (array[size] < array[size * 2 + 2])
            swap_value(array, size, size * 2 + 2);
    }
    heapify_pop(heap, size++, array);
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    if (heap->size > 1)
        heapify_pop(heap, 0, heap->array);
    return root;
}
*/

static void makeheap(int *array, int size, int i)
{
    int max = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && array[left] > array[max])
        max = left;
    if (right < size && array[right] > array[max])
        max = right;
    if (max != i)
    {
        swap_value(array, i, max);
        makeheap(array, size, max);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);
    int head = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
    {
        makeheap(heap->array, heap->size, i);
    }
    return head;
}
