#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void bubble_sort(int array[], size_t size)
{
    size_t index;
    for (size_t i = 1; i < size; i++)
    {
        for (size_t k = 0; k < (size - i); k++)
        {
            if (array[k] > array[k + 1])
            {
                index = array[k];
                array[k] = array[k + 1];
                array[k + 1] = index;
            }
        }
    }
}
