#include "list.h"

#include <stdlib.h>
#include <string.h>
/*
#include <stdio.h>
*/

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return NULL;
    new->data = malloc(data_size);
    if (!new->data)
        return NULL;
    memcpy(new->data, value, data_size);
    new->next = list;
    return new;
}

size_t list_length(struct list *list)
{
    size_t size = 0;
    while (list)
    {
        list = list->next;
        size++;
    }
    return size;
}

void list_destroy(struct list *list)
{
    struct list *tmp = list;
    while (tmp)
    {
        list = list->next;
        free(tmp->data);
        free(tmp);
        tmp = list;
    }
}

/*
void pretty_print(struct list *list)
{
    for (size_t i = 0; i < list_length(list); i++)
    {
        printf("%p\n", list->data);
    }
}


int main()
{
   struct list *l = list_prepend(NULL, "ACU", 3);
   struct list *l1 = list_prepend(l, "ACASD", 5);
   struct list *l2 = list_prepend(l1, 1, 1);
   pretty_print(l2);
   list_destroy(l2);
    return 1;
}
*/
