#include <stdio.h>

#include "list.h"

/*
void list_print(struct list *l)
{
    if (l)
    {
        printf("%d", l->data);
        l = l->next;
        while (l)
        {
            printf(" %d", l->data);
            l = l->next;
        }
    }
}
*/

void list_print2(struct list *l)
{
    if (l != NULL)
    {
        printf("%d", l->data);
        if (l->next)
        {
            printf(" ");
            list_print2(l->next);
        }
    }
}

void list_print(struct list *l)
{
    list_print2(l);
    printf("\n");
}
