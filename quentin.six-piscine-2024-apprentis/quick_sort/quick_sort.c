#include <stddef.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivot(int *str, int min, int max)
{
    int pivot = str[max];
    int index = (min - 1);
    for (int i = min; i <= max - 1; i++)
    {
        if (str[i] < pivot)
        {
            index++;
            swap(&str[index], &str[i]);
        }
    }

    swap(&str[index + 1], &str[max]);
    return (index + 1);
}

void Recursif(int *str, int min, int max)
{
    if (min < max)
    {
        int index = pivot(str, min, max);
        Recursif(str, min, index - 1);
        Recursif(str, index + 1, max);
    }
}

void quicksort(int *tab, int len)
{
    Recursif(tab, 0, (len - 1));
}
