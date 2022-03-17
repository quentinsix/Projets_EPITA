#include <stddef.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (tab != NULL && len != 0)
    {
        *max = *tab;
        *min = *tab;
        for (size_t i = 0; i < len; i++)
        {
            if (*max < tab[i])
                *max = tab[i];
            if (*min > tab[i])
                *min = tab[i];
        }
    }
}
