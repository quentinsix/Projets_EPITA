#include "my_itoa_base.h"
//#include <stdio.h>
#include <stddef.h>
//#include <stdlib.h>

size_t my_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    size_t base_ = my_strlen(base);
    size_t i = 0, nb = 0;
    int t = n;
    if (n < 0)
        n = -n;
    while (n != 0)
    {
        s[i++] = base[n % base_];
        n = n / base_;
        nb++;
    }
    i--;
    for (size_t j = 0; j < nb / 2; j++)
    {
        char tmp = s[j];
        s[j] = s[i - j];
        s[i - j] = tmp;
    }
    if (t < 0)
    {
        i++;
        for (size_t j = i; j > 0; j--)
            s[j] = s[j - 1];
        s[0] = '-';
    }
    s[++i] = '\0';
    return s;
}

/*
int main()
{
    char *s = malloc(sizeof(char) * 10);
    char *a = malloc(sizeof(char) * 10);
    char *b = malloc(sizeof(char) * 10);
    char *c = malloc(sizeof(char) * 10);
    printf("%s\n",my_itoa_base(42, s, "0123456789ABCDEF"));
    printf("%s\n",my_itoa_base(32, a, "0123456789abcdef"));
    printf("%s\n",my_itoa_base(12, b, "01"));
    printf("%s\n",my_itoa_base(8098, c, "0123456789"));
    char *d = malloc(sizeof(char) * 10);
    char *e = malloc(sizeof(char) * 10);
    printf("%s\n",my_itoa_base(-1298, d, "0123456789"));
    printf("%s\n",my_itoa_base(-1, e, "0123456789"));
    return 0;
}
*/
