#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        int i = 1, j = 1;
        while (j <= n)
        {
            i++;
            j = (i * i);
        }
        return (i - 1);
    }
}

/*
int main()
{
    printf("%d\n",int_sqrt(1));
    printf("%d\n",int_sqrt(-5));
    printf("%d\n",int_sqrt(0));
    printf("%d\n",int_sqrt(25));
    printf("%d\n",int_sqrt(8));
    return 0;
}
*/
