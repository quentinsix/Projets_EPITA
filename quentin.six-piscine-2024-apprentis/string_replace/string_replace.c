#include "string_replace.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    if (s != NULL)
    {
        while (s[i] != '\0')
            i++;
    }
    return i;
}

size_t NbTotal(char c, const char *str, const char *pattern)
{
    int i = 0;
    size_t nb = 0;
    size_t add = my_strlen(pattern);
    while (str[i] != '\0')
    {
        if (str[i] == c && pattern != NULL)
            nb += add;
        else if (str[i] != c)
            nb++;
        i++;
    }
    return nb + 1;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;
    // printf("%ld ", NbTotal(c, str, pattern));
    char *newstr = malloc(sizeof(char) * NbTotal(c, str, pattern));
    int i = 0;
    int a = 0;
    int iStr = 0;
    while (str[i] != '\0')
    {
        if (c == str[i] && pattern != NULL)
        {
            while (pattern[a] != '\0')
            {
                newstr[iStr] = pattern[a];
                iStr++;
                a++;
            }
        }
        if (c != str[i])
        {
            newstr[iStr] = str[i];
            iStr++;
        }
        a = 0;
        i++;
    }
    newstr[iStr] = '\0';
    return newstr;
}
/*
void check(char c, const char *s, const char *p)
{
    char *res = string_replace(c, s, p);

    printf("%s\n", res);
    free(res);
}

int main(void)
{
    check('o', "bobo", "");
    //check('o', "bobo", "i");
    //check('o', "bobo", "oo");

    return 0;
}
*/
