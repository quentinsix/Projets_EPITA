#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    if (n == 0)
        return NULL;
    struct vector *new = malloc(sizeof(struct vector));
    if (!new)
        return NULL;
    if (new != NULL)
    {
        new->size = 0;
        new->capacity = n;
        new->data = (int *)malloc(sizeof(int) * new->capacity);
        if (new->data == NULL)
            return NULL;
    }
    return new;
}

void vector_destroy(struct vector *v)
{
    if (v != NULL)
    {
        free(v->data);
        free(v);
    }
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v != NULL && n != v->capacity && n > 0)
    {
        // printf("on realloc");
        v->capacity = n;

        int *tab = (int *)realloc(v->data, sizeof(int) * v->capacity);
        if (tab == NULL)
            return NULL;
        /*
        for (size_t i = 0; i < v->capacity; i++)
            tab[i] = v->data[i];
        free(v->data);
        */
        v->data = tab;
        if (n < v->size)
            v->size = n;
    }
    return v;
}

void vector_print(const struct vector *v)
{
    if (v != NULL)
    {
        if (v->size > 0)
        {
            size_t i = 1;
            printf("%d", v->data[0]);
            while (i != v->size)
            {
                printf(",%d", v->data[i]);
                i++;
            }
        }
    }
    putchar('\n');
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v != NULL)
    {
        if (v->size == v->capacity)
            v = vector_resize(v, 2 * v->capacity);
        v->data[(int)v->size] = elt;
        v->size++;
    }
    return v;
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v != NULL)
    {
        vector_destroy(v);
    }
    return vector_init(n);
}

void insert_data(int *tabl, size_t index, int elt, size_t size)
{
    for (size_t i = size; i > index; i--)
        tabl[i] = tabl[i - 1];
    tabl[index] = elt;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v != NULL && i <= v->size)
    {
        if (v->size == v->capacity)
            v = vector_resize(v, 2 * v->capacity);
        insert_data(v->data, i, elt, v->size);
        v->size++;
        return v;
    }
    return NULL;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v != NULL && i < v->size)
    {
        for (size_t a = i; a < v->size; a++)
            v->data[(int)a] = v->data[(int)(a + 1)];
        v->size--;
        if (v->size < v->capacity / 2)
            v = vector_resize(v, v->capacity / 2);
        return v;
    }
    return NULL;
}

/*
int main()
{
    //struct vector *v = vector_init(8);
    struct vector *v = vector_init(1);
    printf("INIT taille = %ld, capacity = %ld\n", v->size,v->capacity);
    vector_insert(v, 0, 3);
    vector_insert(v, 0, 3);
    vector_insert(v, 0, 3);
    vector_insert(v, 0, 3);

    vector_insert(v, 0, 3);
    vector_insert(v, 0, 3);

    vector_remove(v, 0);
    vector_remove(v, 0);

    vector_remove(v, 0);
    vector_remove(v, 0);
    vector_remove(v, 0);

    printf("taille = %ld, capacity = %ld\n", v->size,v->capacity);

    vector_print(v);
    vector_destroy(v);
}
*/
