#include <stdio.h>

int prout(char a)
{
    switch (a)
    {
    case ' ':
        return 1;
    case '\t':
        return 1;
    case '\n':
        return 1;
    case '\f':
        return 1;
    case '\v':
        return 1;
    case '\r':
        return 1;
    case '\b':
        return 1;
    default:
        return 0;
    }
}

int count_words(const char *file_in)
{
    char c;
    int words = 0, new = 0;
    FILE *fd = fopen(file_in, "r");
    if (fd == NULL)
        return -1;
    c = fgetc(fd);
    if (c == -1)
    {
        fclose(fd);
        return 0;
    }
    else if (c != '\n' && prout(c))
    {
        c = fgetc(fd);
        while (prout(c))
            c = fgetc(fd);
        words++;
    }
    while ((c = fgetc(fd)) != EOF)
    {
        if (prout(c))
        {
            while (prout(c))
                c = fgetc(fd);
            words++;
            new = 1;
        }
        else
            new = 0;
    }
    fclose(fd);
    if (c != '\n' && !new)
        words++;
    if (words == 1 && prout(c))
        return 0;
    return words;
}
