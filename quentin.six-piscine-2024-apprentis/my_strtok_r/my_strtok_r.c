#include "my_strtok_r.h"

#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    if (accept == NULL || s == NULL)
        return 0;

    const char *s1 = s, *tmp;
    while (*s)
    {
        for (tmp = accept; *tmp; tmp++)
        {
            if (*s == *tmp)
                break;
        }

        if (*tmp == '\0')
            break;
        s++;
    }
    return s - s1;
}

char *my_strchr(const char *str, const char occur)
{
    while (*str != occur && *str != '\0')
        str++;
    if (*str == occur)
        return (char *)str;
    return NULL;
}

char *To_String(const char *s1, const char *s2)
{
    if ((s1 == NULL) || (s2 == NULL))
        return NULL;
    while (*s1)
    {
        if (my_strchr(s2, *s1))
            return (char *)s1;
        else
            s1++;
    }
    return NULL;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    // token pour relancer le truc
    char *token;
    if (str == NULL)
        str = *saveptr;
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    token = str;
    str = To_String(token, delim);
    if (str == NULL)
        *saveptr = my_strchr(token, '\0');
    else
    {
        *str = '\0';
        *saveptr = str + 1;
    }
    return token;
}
