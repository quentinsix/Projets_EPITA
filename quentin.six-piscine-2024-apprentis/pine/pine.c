#include <stdio.h>

int pine(unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n - i - 1; j++)
        {
            putchar(' ');
        }
        for (unsigned k = 0; k < 1 + 2 * i; k++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    for (unsigned i = 0; i < n / 2; i++)
    {
        for (unsigned j = 0; j < n - 1; j++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    if (n < 3)
        return 1;
    return 0;
}
