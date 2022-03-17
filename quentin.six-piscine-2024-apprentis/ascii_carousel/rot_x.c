#include <stddef.h>

void rot_x(char *s, int x)
{
    if (s != NULL)
    {
        int i = 0;
        int result = 0;
        while (s[i] != '\0')
        {
            if ('A' <= s[i] && 'Z' >= s[i])
            {
                result = s[i] - 65 + x;
                if (result < 0)
                    result += 26;
                s[i] = result % 26 + 65;
            }
            if ('a' <= s[i] && 'z' >= s[i])
            {
                result = s[i] - 97 + x;
                if (result < 0)
                    result += 26;
                s[i] = result % 26 + 97;
            }
            i++;
        }
    }
}
