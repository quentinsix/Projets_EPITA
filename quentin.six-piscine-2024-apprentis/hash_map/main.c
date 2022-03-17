#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main()
{
    struct hash_map *nul = hash_map_init(0);

    struct hash_map *ht = hash_map_init(7);
    bool *updated = malloc(sizeof(bool));
    *updated = false;

    hash_map_insert(nul, "ACU", "1", updated);

    hash_map_insert(ht, "ACU", "1", updated);
    //*updated = false;
    hash_map_insert(ht, "YAKA", "2", updated);
    //*updated = false;
    hash_map_insert(ht, "YAKA", "92", updated);
    //*updated = false;
    hash_map_insert(ht, "KRISBUOL", "3", updated);
    //*updated = false;
    hash_map_insert(ht, "SHALOM", "4", updated);
    //*updated = false;
    hash_map_insert(ht, "DAMN", "5", updated);
    //*updated = false;

    printf("%s\n", hash_map_get(ht, "YAKA"));
    printf("%d\n", NULL == hash_map_get(ht, "joe"));
    hash_map_dump(ht);
    free(updated);
    hash_map_free(ht);
    hash_map_free(nul);
    return 0;
}
