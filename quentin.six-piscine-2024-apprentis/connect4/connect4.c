#include "connect4.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct point
{
    size_t x;
    size_t y;
    size_t total;
};


int IsValPoint(int x, int y, int width, int height)
{
    return (x >= 0 && y >= 0 && y <= width && x <= height);
}

/*
int checkGrid(char *tabl[], size_t col, size_t lines)
{
    if ( col < 4 && lines < 4)
        return 1;
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            char c = tabl[i][j];
            if (c != 'O' && c != 'X' && c != '-')
                return 1;
        }
    }
    return 0;
}
*/

int Recur(char *tabl[], size_t c, size_t l, struct point)
{

}

int connect4(char *game[], size_t columns, size_t lines)
{

}

void display(char *tabl[], size_t col, size_t lines)
{
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%c ", tabl[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    char **tabl = malloc(sizeof(char) * 3);
    for (int i = 0; i < 3; i++)
        tabl[i] = malloc(sizeof(char) * 3);
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3;j++)
        {
            tabl[i][j] = (char) (i+ 65);
        }
    }
    //{ '1','2','3','4','5','6','7','8','9'};

    display(tabl, 3, 3);

}
