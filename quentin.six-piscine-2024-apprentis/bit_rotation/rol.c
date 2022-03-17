#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    while (roll != 0)
    {
        if (value >= 128)
        {
            value = value << 1;
            value++;
        }
        else
            value = value << 1;
        roll--;
    }
    return value;
}
