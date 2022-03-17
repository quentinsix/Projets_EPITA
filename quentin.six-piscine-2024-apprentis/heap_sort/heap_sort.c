#include "heap_sort.h"

#include <stddef.h>

void heapify(int *array, size_t size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify_index(array, size, i);
    }
}

void swap(int *s1, int *s2)
{
    int temp = *s2;
    *s2 = *s1;
    *s1 = temp;
}

void heapify_index(int array[], int size, int node)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        int max = node;
        int left = (2 * node) + 1;
        int right = (2 * node) + 2;
        if (left < size && array[left] > array[max])
        {
            max = left;
        }
        if (right < size && array[right] > array[max])
        {
            max = right;
        }
        if (max != node)
        {
            swap(&array[node], &array[max]);
            heapify_index(array, size, max);
        }
    }
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);
    for (int i = (size - 1); i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        heapify_index(array, i, 0);
    }
}
