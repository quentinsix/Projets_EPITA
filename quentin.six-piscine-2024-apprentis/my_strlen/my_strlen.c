#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

size_t my_strlen(const char *str)
{
    if (!str)
        return 0;
    size_t i = 0;
    while (str[i] != '\0')
        ++i;
    return i;
}
