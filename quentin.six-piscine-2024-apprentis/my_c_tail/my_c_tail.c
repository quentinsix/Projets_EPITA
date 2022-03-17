#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>

size_t my_strlen(char *s)
{
    size_t i = 0;
    while (s[i])
        ++i;
    return i;
}

void stdintail(unsigned int n)
{
    char *buffer = calloc(1024, sizeof(char));
    ssize_t g = read(STDIN_FILENO, buffer, 1024);
    ssize_t g2 = g;
    unsigned nb_lignes = 1;
    char *yy = buffer;
    char *buffer2 = buffer;
    while (g2 > 0)
    {
        if (*yy == '\n')
        {
            nb_lignes++;
        }
        yy++;
        g2--;
    }
    unsigned i = 1;
    if (nb_lignes <= n)
    {
        write(STDOUT_FILENO, buffer, my_strlen(buffer));
        free(buffer);
        return;
    }
    unsigned h = nb_lignes - n;
    while (i < h)
    {
        if (*buffer2 == '\n')
        {
            i++;
        }
        buffer2++;
    }
    write(STDOUT_FILENO, buffer2, my_strlen(buffer2));
    free(buffer);
}
