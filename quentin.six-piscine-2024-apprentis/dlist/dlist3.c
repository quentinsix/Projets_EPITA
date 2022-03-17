#include <stddef.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (list)
    {
        struct dlist_item *tmp = list->head;
        while (tmp)
        {
            tmp->data *= tmp->data;
            tmp = tmp->next;
        }
    }
}

void dlist_reverse(struct dlist *list)
{
    if (list)
    {
        struct dlist_item *tmp = list->head;
        struct dlist_item *tmp2 = tmp->prev;
        while (tmp)
        {
            tmp2 = tmp->next;
            tmp->next = tmp->prev;
            tmp->prev = tmp2;
            tmp = tmp2;
        }
        tmp = list->tail;
        list->tail = list->head;
        list->head = tmp;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (list == NULL || index > list->size)
        return NULL;
    if (list->size == 0)
    {
        free(list);
        return dlist_init();
    }
    struct dlist *list2 = dlist_init();
    list2->size = list->size - index;
    list2->tail = list->tail;
    struct dlist_item *tmp = list->head;
    size_t i = 0;
    if (list->size < index)
    {
        i = index;
        tmp = list->tail;
        while (i != index)
        {
            i -= 1;
            tmp = tmp->prev;
        }
    }
    else
    {
        while (i != index)
        {
            i += 1;
            tmp = tmp->next;
        }
    }
    list->tail = tmp->prev;
    list->size -= list2->size;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    list2->head = tmp;
    return list2;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list1 != NULL && list2 != NULL)
    {
        if (list1->size == 0)
        {
            list1->tail = list2->tail;
            list1->head = list2->head;
        }
        if (list2->size != 0)
        {
            list1->tail->next = list2->head;
            list2->head->prev = list1->tail;
            list1->tail = list2->tail;
            list1->size += list2->size;
        }
        list2->head = NULL;
        list2->tail = NULL;
        list2->size = 0;
    }
}
