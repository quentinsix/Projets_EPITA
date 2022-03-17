#include <stddef.h>
#include <stdio.h>
#include <string.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    if (num == 0)
        return 0;
    const char *string1 = s1, *string2 = s2;
    size_t i = 0;
    while (i < num && string1[i] != '\0' && string2[i] != '\0')
    {
        if (string1[i] == string2[i])
            i++;
        else
            break;
    }
    if (string1[i] == '\0' && string2[i] == '\0' && i < num - 1)
        return -1;
    return string1[i] - string2[i];
}
