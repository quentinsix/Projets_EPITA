#include <stddef.h>
char *my_strcpy(char *dest, const char *source)
{
    if (dest == NULL || source == NULL)
        return NULL;
    int i = 0;
    char *head = dest;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return head;
}
