#include "fifo.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *new = malloc(sizeof(struct fifo));
    struct list *head = malloc(sizeof(struct list));
    struct list *tail = malloc(sizeof(struct list));
    if (!new || !head || !tail)
        return NULL;
    head->next = NULL;
    tail->next = NULL;
    new->size = 0;
    new->head = head;
    new->tail = tail;
    return new;
}

size_t fifo_size(struct fifo *fifo)
{
    size_t size = 0;
    struct list *list = fifo->head;
    while (list)
    {
        list = list->next;
        size++;
    }
    return size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *newlist = malloc(sizeof(struct list));
    newlist->data = elt;
    fifo->size++;
    if (fifo_size(fifo) == 0)
    {
        newlist->next = NULL;
        fifo->tail = newlist;
        fifo->head = newlist;
    }
    else
    {
        newlist->next = fifo->tail;
        fifo->tail = newlist;
    }
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    size_t size = fifo_size(fifo);
    if (size != 0)
    {
        size_t i = 0;
        struct list *tmp = fifo->head;
        while (i < size - 2)
        {
            i++;
            //printf("%d ",tmp->data);
            tmp = tmp->next;
        }
         //printf("je vaut %d sfd",tmp->data);
        free(fifo->tail);
        fifo->tail = tmp;
       
        if (size == 1)
        {
            fifo->tail = NULL;
            fifo->head = NULL;
        }
        
        printf("caca ");
        tmp->next = NULL;
    }
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->head != NULL)
        fifo_pop(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *tmp = fifo->tail;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
int main()
{
    struct fifo *fifo = fifo_init();
    fifo_push(fifo, 1);
    fifo_push(fifo, 2);
    fifo_push(fifo, 5);
    fifo_push(fifo, 8);
    fifo_push(fifo, 15);
    fifo_print(fifo);
    //fifo_pop(fifo);
    printf("fifo clear");
    //fifo_clear(fifo);
    //printf("taille est de %ld\n", fifo_size(fifo));
}
