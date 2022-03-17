#include <stddef.h>
//#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(struct dlist *list, size_t index)
{
    size_t size = dlist_size(list);
    if (index > size - 1)
        return -1;
    struct dlist_item *new = list->head;
    size_t i = 0;
    while (i != index)
    {
        i++;
        new = new->next;
    }
    return new->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    size_t size = dlist_size(list);
    if (list == NULL || element < 0 || size + 1 < index)
        return -1;
    struct dlist_item *new = malloc(sizeof(struct dlist_item) * 1);
    new->data = element;
    struct dlist_item *tmp = list->head;
    size_t i = 0;
    // printf("num = %d\n", tmp->data);
    if (index == 0)
    {
        dlist_push_front(list, element);
        free(new);
        list->size -= 1;
    }
    else
    {
        while (i != index - 1)
        {
            i++;
            tmp = tmp->next;
        }

        if (index == size)
        {
            dlist_push_back(list, element);
            free(new);
            list->size -= 1;
        }
        else
        {
            new->next = tmp->next;
            new->next->prev = new;
            tmp->next = new;
            new->prev = tmp;
        }
    }
    list->size += 1;
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (list == NULL || element < 0)
        return 0;
    struct dlist_item *tmp = list->head;
    int i = 0;
    while (tmp)
    {
        if (tmp->data == element)
            return i;
        tmp = tmp->next;
        i++;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (list == NULL || list->size == 0)
        return -1;
    size_t size = list->size, i = 0;
    struct dlist_item *tmp = list->head;
    if (size <= index)
        return -1;
    while (i != index)
    {
        tmp = tmp->next;
        i++;
        // printf("%d\n ",i);
    }
    if (index == 0)
        list->head = tmp->next;
    if (index == size - 1)
        list->tail = tmp->prev;
    if (tmp->prev)
    {
        tmp->prev->next = tmp->next;
    }
    if (tmp->next)
    {
        tmp->next->prev = tmp->prev;
    }
    int r = tmp->data;
    free(tmp);
    list->size -= 1;
    return r;
}
