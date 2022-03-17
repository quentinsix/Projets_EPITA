#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
/*
#include <stdio.h>
#include <string.h>
*/
int CharOk(const char *accept, char c)
{
    int i = 0;
    while (accept[i] != '\0')
    {
        if (accept[i] == c)
            return 0;
        i++;
    }
    return 1;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t nb = 0;
    int index = 0;
    while (s[index] != '\0')
    {
        if (CharOk(accept, s[index]) == 0)
            nb++;
        else
            return nb;
        index++;
    }
    return nb;
}

/*
int main()
{
    printf("%ld %ld\n", my_strspn("azeaze","aze"),strspn("azeaze","aze"));
    printf("%ld %ld\n", my_strspn("az00eaze","aze"),strspn("az00eaze","aze"));
    printf("%ld %ld\n", my_strspn("azeaze",""),strspn("azeaze",""));
    printf("%ld %ld\n", my_strspn("","aze"),strspn("","aze"));
    return 0;
}
*/
