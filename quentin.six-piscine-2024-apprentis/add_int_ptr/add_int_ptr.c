#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
int *add_int_ptr(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return a;
    *a = *b + *a;
    return a;
}
/*
int main()
{
    int x = 15, y = 6;
    int *c = add_int_ptr(&x,&y);
    printf("%d",*c);
    return 0;
}
*/
