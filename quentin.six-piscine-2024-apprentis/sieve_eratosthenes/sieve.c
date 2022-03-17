#include <stddef.h>
#include <stdio.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    int arr[1000] = { 2 };
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
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
            printf("%d\n", i);
    }
    return;
}

