#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    char letter = 'a';
    while (letter != 'z')
    {
        putchar(letter);
        putchar(' ');
        letter++;
    }
    putchar(letter);
    putchar('\n');
    return 0;
}
