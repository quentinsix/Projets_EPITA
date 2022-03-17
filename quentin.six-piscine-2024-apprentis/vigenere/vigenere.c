#include "vigenere.h"

int ToUp(const char c)
{
    if (c <= 'z' && c >= 'a')
        return (c - 32);
    return c;
}

int CharOk(const char c)
{
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
    {
        return 0;
    }
    return 1;
}

void cipher(const char *key, const char *msg, char *res)
{
    int i = 0;
    int iKey = 0;
    while (msg[i] != '\0')
    {
        if (CharOk(msg[i]) == 0)
        {
            if (key[iKey] == '\0')
                iKey = 0;
            res[i] = (((ToUp(msg[i]) + ToUp(key[iKey]) - 130) % 26) + 65);
            iKey++;
        }
        else
        {
            res[i] = msg[i];
        }
        i++;
    }
}

void decipher(const char *key, const char *msg, char *res)
{
    int i = 0;
    int iKey = 0;
    int result = 0;
    while (msg[i] != '\0')
    {
        if (CharOk(msg[i]) == 0)
        {
            if (key[iKey] == '\0')
                iKey = 0;
            result = ToUp(msg[i]) - ToUp(key[iKey]);
            if (result < 0)
                result += 26;
            res[i] = (result % 26) + 65;
            iKey++;
        }
        else
        {
            res[i] = msg[i];
        }
        i++;
    }
}
