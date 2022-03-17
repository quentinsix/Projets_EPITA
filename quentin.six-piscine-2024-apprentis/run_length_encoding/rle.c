#include <stddef.h>
#include <stdlib.h>
//#include <stdio.h>

/*
size_t my_strlen(const char *str)
{
    if (!str)
        return 0;
    size_t i = 0;
    size_t nb = 0;
    size_t total = 0;
    char c = str[0];
    while (str[i] != '\0')
    {
        while (c == str[i])
        {
            nb++;
            i++;
        }
        total += nb;
        nb = 0;
        c = str[i];
    }
    return total + 1;
}
*/

char *rle_encode(const char *s)
{
    if (s[0] == '\0')
        return NULL;
    size_t total = 3;
    char *code = malloc(sizeof(char) * total);
    int nb = 0, iEn = 0, i = 0;
    char c = s[0];
    while (s[i] != '\0')
    {
        if (nb == 9)
        {
            total += 2;
            code = realloc(code, total);
            code[iEn++] = nb + 48;
            code[iEn++] = c;
            nb = 0;
        }
        if (c == s[i])
        {
            nb++;
        }
        else
        {
            total += 2;
            code = realloc(code, total);
            code[iEn++] = nb + 48;
            code[iEn++] = c;
            c = s[i];
            nb = 1;
        }
        i++;
    }
    code[iEn++] = nb + 48;
    code[iEn++] = c;
    code[iEn] = '\0';
    return code;
}

int NbChar(const char *s)
{
    if (s == NULL)
        return -1;
    int nb = 0;
    int i = 0;
    char c;
    while (s[i] != '\0')
    {
        c = s[i + 1];
        if (c == '\0' && s[i] <= '9' && s[i] >= '0')
            return -1;
        if (s[i] > '9' || s[i] < '0')
            return -1;
        nb += s[i] - 48;
        i = i + 2;
    }
    return nb + 1;
}

char *rle_decode(const char *s)
{
    int len = NbChar(s);
    if (len <= 0)
    {
        return NULL;
    }
    char *decode = malloc(sizeof(char) * len);
    int i = 0;
    int tmp = 0;
    int index = 0;
    while (s[i] != '\0')
    {
        tmp = s[i] - 48;
        while (tmp > 0)
        {
            decode[index] = s[i + 1];
            index++;
            tmp--;
        }
        i = i + 2;
    }
    decode[index] = '\0';
    return decode;
}

/*
int main()
{
    char *st = rle_encode("Cheeeeehhhh");
    printf("%s\n",st);
    free(st);
    //printf("%s\n", rle_decode(rle_encode("C")));
    //printf("%s\n", rle_encode("Cheeeeeeeehhhhhhh"));
    //printf("%s\n", rle_decode(rle_encode("abcdefghijklmnopqrstuvwxyz")));

    //printf("%d\n", NbChar("1A3B5Z1A"));
    //char *a = malloc(NbChar("1A3B5Z1A"));
    //printf("%s\n", rle_decode("1A3B5Z1A"));
 //   printf("%s\n", rle_decode(rle_encode("Cheeeeeeeehhhhhhh")));
//    printf("%s\n", rle_decode(rle_encode("abcdefghijklmnopqrstuvwxyz")));
    //free(a);
}
*/
