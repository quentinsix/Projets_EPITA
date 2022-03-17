#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
void my_strlowcase(char *str)
{
    while (*str != '\0')
    {
        if (*str <= 'Z' && *str >= 'A')
            *str += 32;
        str++;
    }
}
/*
int main(void)
{
    char str[] = "azerty1234XYZ &(";
    my_strlowcase(str);
    puts(str);
    return 0;
}
*/
