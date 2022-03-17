#include "my_itoa.h"

#include <stddef.h>
//#include <stdio.h>

//#include <stdlib.h>
//#include <limits.h>

char *my_itoa(int value, char *s)
{
    int i = 0;
    if (value == 0)
    {
        s[i++] = 0 + 48;
        s[i] = '\0';
        return s;
    }
    if (value < 0)
    {
        s[i] = '-';
        value = -value;
        i++;
    }
    /*
    if (value == INT_MAX)
        i++;
        */
    size_t tmp = (size_t)value;
    int nb = 1;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        nb *= 10;
    }
    nb = nb / 10;
    while (nb != 0)
    {
        s[i] = 48 + value / nb;
        value = value % nb;
        nb = nb / 10;
        i++;
    }
    s[i] = '\0';
    return s;
}

/*
int main()
{
    char *s = malloc(sizeof(char) * 20);
    printf("%d  %s\n", INT_MAX, my_itoa(INT_MAX,s));
    return 1;
}
*/
