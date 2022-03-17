#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
void str_revert(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    char tmp;
    for (int i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}
/*
int main(void)
{
    char foo[] = "u";
    str_revert(foo);
    char caca[] = "af";
    str_revert(caca);
    printf("%s\n%s\n", foo,caca); // "uof"
}
*/
