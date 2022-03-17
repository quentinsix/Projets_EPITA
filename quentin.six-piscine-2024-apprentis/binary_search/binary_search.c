#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/

int binary_search(const int vec[], size_t size, int elt)
{
    int indexDebut = 0;
    int indexFin = size - 1;
    int pivot = indexFin / 2;
    while (indexDebut <= indexFin)
    {
        pivot = (indexDebut + indexFin) / 2;
        if (vec[pivot] == elt)
        {
            return pivot;
        }
        else if (vec[pivot] < elt)
        {
            indexDebut = pivot + 1;
        }
        else
        {
            indexFin = pivot - 1;
        }
    }
    if (indexDebut == indexFin)
    {
        return pivot;
    }
    return -1;
}
/*
int main(void)
{
    const int vect[]=
    {
        1,2,3,8,9,12
    };
    int pivot = binary_search(vect,6,5);
    printf("%d",pivot);
    pivot = binary_search(vect,6,0);
    printf("%d",pivot);
    return 0;
}
*/
