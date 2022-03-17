#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int main()
{
    struct dlist *l = dlist_init();
    dlist_insert_at(l, 0, 0);
    dlist_insert_at(l, 1, 0);
    dlist_insert_at(l, 2, 0);
    dlist_insert_at(l, 3, 0);
    dlist_insert_at(l, 4, 0);
    struct dlist *l2 = dlist_split_at(l, 3);
    printf("list1 = \n");
    dlist_print(l);
    printf("list12 = \n");
    dlist_print(l2);
    while (l->size != 0)
        dlist_remove_at(l, 0);
    while (l2->size != 0)
        dlist_remove_at(l2, 0);
    free(l2);
    free(l);
    return 0;
}
