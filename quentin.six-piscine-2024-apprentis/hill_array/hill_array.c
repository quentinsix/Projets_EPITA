#include <asset.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
    {
        return - 1;
    }
    int change1 = 0;
    int change2 = 0;
    int i = 0;
    int indexMax = len - 1;
    while (i < indexMax)
    {
        if (change1 == 0 && change2 == 1)
            return - 1;
        if (tab[i] >
    }
    return i;
}

int main(void)
{
    int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, 0 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab1, 10));
    int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab2, 10));
    int tab3[] = { 1, 2, 3, 4, 6, 6, 4, 5, 0, 0 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab3, 10));
    return 0;
}
