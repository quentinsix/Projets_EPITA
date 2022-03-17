#include "my_atoi_base.h"

//#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int my_strlen1(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int index_of(char c, const char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return i;
        i += 1;
    }
    return 0;
}

int isCharOk(const char *str, const char *base)
{
    int i = 0, j, nbsign = 0, debut = 0;
    while (str[i])
    {
        if (str[i] == ' ' && debut == 1)
        {
            return -1;
        }
        while (str[i] == ' ')
            i++;
        debut = 1;
        while (str[i] == '+' || str[i] == '-')
        {
            i++;
            nbsign++;
        }
        while (base[j] != '\0' && base[j] != str[i])
            j++;
        if (base[j] == '\0')
            return -1;
        j = 0;
        i++;
    }
    if (nbsign > 1)
        return -1;
    return 0;
}

int my_atoi_base(const char *str, const char *base)
{
    if (isCharOk(str, base) == -1)
        return 0;
    int n = 0, i = 0, len, sign;
    while (str[i] == ' ')
        i++;
    if (str == NULL || base == NULL)
        return 0;
    sign = 1;
    if (str[i] == '-')
        sign *= -1;
    len = my_strlen1(base);
    while (str[i] != '\0')
    {
        n = n * (len * ((sign * n >= 0) ? 1 : sign));
        n = n + (index_of(str[i], base) * sign);
        i += 1;
    }
    return (n);
}

int main()
{
    printf("%d\n",my_atoi_base("WQ1WW", "QW"));
    printf("%d\n",my_atoi_base("++77", "01234567"));
    printf("%d\n",my_atoi_base("  -!!!@$$$!#", "!@#$"));
    printf("%d\n",my_atoi_base("+ 77", "01234567"));
    /*
    assert(my_atoi_base("WQ1WW", "QW"));
    assert(my_atoi_base("++77", "01234567") == (0));
    assert(my_atoi_base("  -!!!@$$$!#", "!@#$") == (-2034));
    assert(my_atoi_base("+ 77", "01234567") == (0));
    */

    printf("%d\n", my_atoi_base("ff", "0123456789abcdef"));
    printf("%d\n", my_atoi_base("-ff", "0123456789abcdef"));
    printf("%d\n", my_atoi_base("77", "01234567"));
    printf("%d\n", my_atoi_base("WQWW", "QW"));
    return 1;
}
