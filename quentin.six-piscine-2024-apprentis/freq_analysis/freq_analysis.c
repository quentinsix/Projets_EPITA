#include <stdio.h>

int my_strlen(const char *str)
{
    if (!str)
        return 0;
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int nbIndexHigh(int letters[], int indexElt)
{
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] > letters[indexElt])
        {
            result++;
        }
    }
    return result;
}

void freq_analysis(const char text[], const char table[])
{
    int str_len2 = my_strlen(text);
    int letters[26] = { 0 };
    for (int i = 0; i < str_len2; i++)
    {
        letters[text[i] - 65]++;
    }
    int index = 0;
    char table2[26] = { 0 };
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
        {
            index = nbIndexHigh(letters, i);
            while (table2[index] != 0)
                index++;
            printf("%c %c\n", i + 65, table[index]);
            table2[index] = 1;
        }
    }
}
