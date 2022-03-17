#include "levenshtein.h"

#include <stddef.h>

size_t my_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}

size_t leven(const char *s1, const char *s2, size_t len1, size_t len2)
{
    int i = 0, j = i, k = j;
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;
    if (s1[len1 - 1] == s2[len2 - 1])
        return leven(s1, s2, len1 - 1, len2 - 1);
    i = leven(s1, s2, len1 - 1, len2 - 1);
    j = leven(s1, s2, len1, len2 - 1);
    k = leven(s1, s2, len1 - 1, len2);
    if (i > j)
    {
        i = j;
    }
    if (i > k)
    {
        i = k;
    }
    return (i + 1);
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1), len2 = my_strlen(s2);
    size_t res = leven(s1, s2, len1, len2);
    return res;
}
