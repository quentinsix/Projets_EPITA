#include "my_atoi.h"

#include <stddef.h>
//#include <stdio.h>

int strOk(const char *str)
{
    int i = 0;
    int nb = 0;
    char c;
    if (str[i] == '\0')
        return -1;
    while (str[i])
    {
        c = str[i];
        if ((c == ' ' || c == '+' || c == '-') && nb == 1)
            return -1;
        if (c != ' ' && (c < '0' || c > '9') && c != '-' && c != '+')
            return -1;
        if (c == '-' || c == '+')
            nb = 1;
        if (c <= '9' && c >= '0')
            nb = 1;
        if ((c == '-' || c == '+') && str[i + 1] == '\0')
            return -1;
        i++;
    }
    return 0;
}

int my_atoi(const char *str)
{
    if (strOk(str) == -1)
        return 0;
    int nb = 0;
    int sign = 0;
    int i = 0;
    int tmp = 0;
    while ((str[i] < '0' || str[i] > '9') && (str[i] != '+' || str[i] != '-'))
    {
        if (str[i] == '+')
            sign = 1;
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    // printf("%d ", sign);
    while (str[i])
    {
        nb *= 10;
        tmp = str[i] - 48;
        nb += tmp;
        i++;
    }
    if (sign < 0)
        nb = -nb;
    return nb;
}
/*
int main()
{
    printf("%d 0\n", my_atoi("-"));
    printf("%d -7\n", my_atoi("     7"));
    printf("%d 0\n", my_atoi("-5   -7"));
    printf("%d 0\n", my_atoi("7 "));
    printf("%d 0\n", my_atoi("65A"));
    printf("%d 0\n", my_atoi("   --"));
    printf("%d -7543\n", my_atoi("      -7543"));
    printf("%d -7543\n", my_atoi("-7543"));
}
*/
