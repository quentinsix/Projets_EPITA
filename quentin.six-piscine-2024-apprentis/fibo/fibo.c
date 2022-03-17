#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include<stdio.h>
*/
unsigned long fibonacci(unsigned long n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
int main()
{
    printf("%lu\n",fibonacci(1));
    printf("%lu\n",fibonacci(2));
    printf("%lu\n",fibonacci(0));
    printf("%lu\n",fibonacci(10));
    printf("%lu\n",fibonacci(8));
    printf("%lu\n",fibonacci(21));
    return 0;
}
*/
