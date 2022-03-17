#include "my_strcasecmp.h"
int Eq(char a)
{
    if (a <= 'Z' && a >= 'A')
        return a + 32;
    return a;
}

int ReturnCase(char a, char b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (Eq(*s1) != Eq(*s2))
            return ReturnCase(Eq(*s1), Eq(*s2));
        s1++;
        s2++;
    }
    return ReturnCase(Eq(*s1), Eq(*s2));
}
