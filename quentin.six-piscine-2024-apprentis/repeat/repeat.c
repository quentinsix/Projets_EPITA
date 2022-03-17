#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;
    for (int i = 0; i < *argv[2] - 48; i++)
        puts(argv[1]);
    return 0;
}
