#include "bsearch.h"

#include <stddef.h>

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
    {
        return begin;
    }
    int min = 0;
    int max = (end - begin - 1);
    int pivot = (end - begin - 1) / 2;
    while (min <= max)
    {
        pivot = min + (max - min) / 2;
        if (*(begin + pivot) == elt)
        {
            return (begin + pivot);
        }
        else
        {
            if (*(begin + pivot) < elt)
            {
                min = pivot + 1;
            }
            else
            {
                max = pivot - 1;
            }
        }
    }
    if (elt > *(begin + pivot))
    {
        return (begin + pivot + 1);
    }
    else
    {
        return (begin + pivot);
    }
}
