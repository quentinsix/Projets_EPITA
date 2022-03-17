/* lakes-example.c */
#include <stdlib.h>

int IsValPoint(int x, int y, int width, int height)
{
    return (x >= 0 && y >= 0 && y <= width && x <= height);
}

void MarkNeigh(char **map, int x, int y, int w, int h)
{
    map[x][y] = 'A';
    if (IsValPoint(x - 1, y, w, h))
    {
        if (map[x - 1][y] == '.')
            MarkNeigh(map, x - 1, y, w, h);
    }
    if (IsValPoint(x + 1, y, w, h))
    {
        if (map[x + 1][y] == '.')
            MarkNeigh(map, x + 1, y, w, h);
    }
    if (IsValPoint(x, y - 1, w, h))
    {
        if (map[x][y - 1] == '.')
            MarkNeigh(map, x, y - 1, w, h);
    }
    if (IsValPoint(x, y + 1, w, h))
    {
        if (map[x][y + 1] == '.')
            MarkNeigh(map, x, y + 1, w, h);
    }
}

int lakes(char **map, int width, int height)
{
    int nb = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                nb++;
                MarkNeigh(map, i, j, width, height);
            }
        }
    }
    /*
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    */
    return nb;
}

/*
static inline void free_all(char **map, int index)
{
    for (int i = 0; i < index; i++)
        free(map[i]);

    free(map);
}

int main(int argc, char **argv)
{
    char **map;
    FILE *f;
    int x;
    int y;

    if (argc != 2)
        return 1;

    f = fopen(argv[1], "r");
    fscanf(f, "%d %d\n", &x, &y);
    map = malloc(sizeof(char *) * y);
    if (!map)
        return 1;

    for (int i = 0; i < y; i++)
    {
        map[i] = malloc(sizeof(char) * x);
        if (!map[i])
        {
            free_all(map, i);
            return 1;
        }
        for (int j = 0; j < x; j++)
            map[i][j] = fgetc(f);
        fgetc(f);
    }
    printf("%d\n", lakes(map, x, y));
    free_all(map, y);
    fclose(f);
    return 0;
}*/
