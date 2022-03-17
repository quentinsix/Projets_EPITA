#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
unsigned long fibo_iter(unsigned long n)
{
    unsigned long A = 0;
    unsigned long B = 1;
    unsigned long tmp;
    for (unsigned long i = 0; i < n; i++)
    {
        tmp = A + B;
        A = B;
        B = tmp;
    }
    return A;
}
/*
int main()
{
    printf("%lu\n",fibo_iter(1));
    printf("%lu\n",fibo_iter(2));
    printf("%lu\n",fibo_iter(0));
    printf("%lu\n",fibo_iter(10));
    printf("%lu\n",fibo_iter(8));
    printf("%lu\n",fibo_iter(21));
}
*/
