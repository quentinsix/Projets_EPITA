#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int main(int agrc, char *argv[])
{
    if (agrc == 1)
    {
        printf("Hello World!\n");
    }
    else
    {
        for (int i = 1; i < agrc; i++)
            printf("Hello %s!\n", argv[i]);
    }
    return 0;
}
