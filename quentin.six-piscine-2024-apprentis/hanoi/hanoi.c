#include <stdio.h>

void recur(unsigned n, int a, int b, int c)
{
    if (n != 0)
    {
        recur(n - 1, a, c, b);
        putchar(48 + a);
        putchar('-');
        putchar('>');
        putchar(48 + b);
        putchar('\n');
        recur(n - 1, c, b, a);
    }
}

void hanoi(unsigned n)
{
    recur(n, 1, 3, 2);
}
