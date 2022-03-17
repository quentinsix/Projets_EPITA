#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_round(float n)
{
    if (n < 0)
        n -= 0.5;
    else
        n += 0.5;
    return (int)(n);
}
