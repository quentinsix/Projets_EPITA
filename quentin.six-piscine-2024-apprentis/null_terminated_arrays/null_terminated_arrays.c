#include <stddef.h>

void first_reverse(void *array, int size)
{
    char **matrix = array;
    int i = 0, j = size - 1;
    while (i < j)
    {
        char *tmp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = tmp;
        i = i + 1;
        j = j + 1;
    }
}

void second_reverse(void *array, int size)
{
    char ***matrix = array;
    int i = 0, j = size - 1;
    while (i < j)
    {
        char **tmp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = tmp;
        i++;
        j--;
    }
}

void reverse_matrix(const char ***matrix)
{
    int len1 = 0, i;
    while (matrix[len1] != NULL)
        len1++;

    second_reverse(matrix, len1);
    for (i = 0; i < len1; i++)
    {
        int len2 = 0;
        while (matrix[i][len2] != NULL)
            len2++;
        first_reverse(matrix, len2);
    }
}
