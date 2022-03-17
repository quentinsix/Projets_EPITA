#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *popo;
    const char *gay;

    if (!dest || !source)
    {
        return NULL;
    }
    gay = source;
    popo = dest;
    unsigned int i = 0;
    while (i < num)
    {
        popo[i] = gay[i];
        i++;
    }
    return dest;
}
