#include <stddef.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
        return 1;
    const char *str_ptr = str;
    const char *alpha_ptr = alphabet;
    while (*alpha_ptr != '\0' && *str_ptr != '\0')
    {
        while (*alpha_ptr != *str_ptr)
        {
            if (*str_ptr == '\0')
                return 0;
            str_ptr++;
        }
        str_ptr = str;
        alpha_ptr++;
    }
    if (*alpha_ptr == '\0')
        return 1;
    return 0;
}
