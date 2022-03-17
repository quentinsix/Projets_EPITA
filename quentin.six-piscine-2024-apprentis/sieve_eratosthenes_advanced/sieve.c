#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    size_t a = 0;
    if (n <= 2)
        return;
    int *arr = calloc(n + 1, sizeof(int));
    if (arr == NULL)
        return;
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 0)
            a++;
    }
    free(arr);
    printf("%lu\n", a);
    return;
}
