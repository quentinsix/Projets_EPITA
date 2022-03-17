#include "bst_static.h"

#include <stdio.h>
#include <stdlib.h>

void caca(struct value **tab, size_t start, size_t end)
{
    for (size_t i = start; i < end; i++)
        tab[i] = NULL;
}

struct bst *init(size_t capacity)
{
    struct bst *bst = malloc(sizeof(struct bst));
    if (!bst)
        return NULL;
    bst->data = malloc(capacity * sizeof(struct value *));
    if (!bst->data)
    {
        free(bst);
        return NULL;
    }
    caca(bst->data, 0, capacity);
    bst->size = 0;
    bst->capacity = capacity;
    return bst;
}

void add(struct bst *tree, int value)
{
    if (tree == NULL)
        return;
    size_t i = 0;
    while (1)
    {
        if (i >= tree->capacity)
        {
            struct value **tmp = realloc(
                tree->data, 2 * tree->capacity * sizeof(struct value *));
            if (!tmp)
                return;
            tree->data = tmp;
            caca(tree->data, tree->capacity, 2 * tree->capacity);
            tree->capacity *= 2;
        }
        if (tree->data[i] == NULL)
        {
            tree->data[i] = malloc(sizeof(struct value));
            if (!tree->data[i])
                return;
            tree->data[i]->val = value;
            tree->size++;
            break;
        }
        else if (value < tree->data[i]->val)
            i = i * 2 + 1;
        else
            i = i * 2 + 2;
    }
}

int search(struct bst *tree, int value)
{
    if (!tree)
        return -1;
    struct value **tab = tree->data;
    size_t i = 0;
    while (i < tree->capacity)
    {
        if (tab[i] == NULL || tab[i]->val == value)
            break;
        else if (value < tab[i]->val)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    if (tab[i] == NULL)
        return -1;
    return i;
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;
    for (size_t i = 0; i < tree->capacity; i++)
        free(tree->data[i]);
    free(tree->data);
    free(tree);
}
