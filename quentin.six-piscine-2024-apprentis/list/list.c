#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return l;
    new->data = e;
    new->next = l;
    return new;
}

struct list *list_find(struct list *l, int e)
{
    if (l == NULL)
        return NULL;
    while (l != NULL && l->data != e)
        l = l->next;
    return l;
}

struct list *list_remove(struct list *l, int e)
{
    if (l == NULL)
        return NULL;
    else if (l->data == e)
    {
        struct list *item = l->next;
        free(l);
        return item;
    }
    else
    {
        l->next = list_remove(l->next, e);
        return l;
    }
}


struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (l == NULL || e > l->data)
    {
        return list_add(l, e);
    }
    struct list *head = l;
    while (!l->next)
    {
        if (e > l->next->data)
        {
            struct list *tmp = list_add(l->next, e);
            l->next = tmp;
            return head;
        }
        l = l->next;
    }
    if (l->next == NULL)
    {
        struct list *tmp = list_add(NULL, e);
        l->next = tmp;
    }
    return head;
}




struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (l == NULL)
        return NULL;
    struct list *item = NULL;
    if (predicate(l->data))
    {
        item = l->next;
        free(l);
        return list_remove_if(item, predicate);
    }
    else
    {
        l->next = list_remove_if(l->next, predicate);
        return l;
    }
}
