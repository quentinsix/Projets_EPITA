#include <stddef.h>

void plus_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a + *b;
}

void minus_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a - *b;
}

void mult_equal(int *a, int *b)
{
    if (a != NULL && b != NULL)
        *a = *a * *b;
}

int div_equal(int *a, int *b)
{
    if (a != NULL && b != NULL && *b != 0)
    {
        int c = *a % *b;
        *a = *a / *b;
        return c;
    }
    return 0;
}
