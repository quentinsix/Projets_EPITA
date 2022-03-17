#include <stdio.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash)
{
    if (hash)
    {
        for (size_t i = 0; i < hash->size; i++)
        {
            struct pair_list *tmp = hash->data[i];
            if (tmp)
            {
                printf("%s: %s", tmp->key, tmp->value);
                tmp = tmp->next;
                while (tmp)
                {
                    printf(", %s: %s", tmp->key, tmp->value);
                    tmp = tmp->next;
                }
                printf("\n");
            }
        }
    }
}
