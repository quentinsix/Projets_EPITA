#include <stddef.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min = start;
    for (size_t i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
        return;
    unsigned index;
    for (size_t i = 0; i < size - 1; i++)
    {
        index = array_min(arr, (i), size);
        swap(&arr[index], &arr[i]);
    }
}
