#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
int my_abs(int n)
{
    return (n < 0) ? -n : n;
}
/*
int main()
{
    printf("%d\n",my_abs(-1));
    printf("%d\n",my_abs(0));
    printf("%d\n",my_abs(5));
    return 0;
}
*/
