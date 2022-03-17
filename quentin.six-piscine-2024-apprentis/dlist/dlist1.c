#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (list == NULL || element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item) * 1);
    new->data = element;
    new->prev = NULL;
    if (list->tail == NULL)
    {
        list->tail = new;
        new->next = NULL;
    }
    else
    {
        list->head->prev = new;
        new->next = list->head;
    }
    list->head = new;
    list->size += 1;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list != NULL)
    {
        struct dlist_item *elt = list->head;
        elt = list->head;
        while (elt != NULL)
        {
            printf("%d\n", elt->data);
            elt = elt->next;
        }
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (list == NULL || element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    new->data = element;
    new->next = NULL;
    if (list->head == NULL)
    {
        list->head = new;
        new->prev = NULL;
    }
    else
    {
        list->tail->next = new;
        new->prev = list->tail;
    }
    list->tail = new;
    list->size += 1;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    if (list != NULL)
        return list->size;
    return 0;
}

/*
int main()
{
    struct dlist *l = dlist_init();

    dlist_push_front(l,2);
    dlist_push_front(l,4);
    dlist_push_front(l,5);
    dlist_push_back(l,32);
    dlist_push_back(l,99);
    dlist_push_back(l,99);

    dlist_print(l);
}*/
