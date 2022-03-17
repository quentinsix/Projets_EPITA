#include <stddef.h>

int isChar(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    return 0;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    int len = 0;
    int indexD = 0;
    while (s[len] != '\0')
        len++;
    int indexF = len - 1;
    while (indexD < indexF)
    {
        if ((indexF < indexD) || (indexF == indexD))
            return 1;
        while (isChar(s[indexD]) == 0)
            indexD++;
        while (isChar(s[indexF]) == 0)
            indexF--;
        if (s[indexD] != s[indexF])
            return 0;
        indexD++;
        indexF--;
    }
    return 1;
}
