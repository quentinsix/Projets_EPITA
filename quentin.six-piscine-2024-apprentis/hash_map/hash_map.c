#include "hash_map.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct hash_map *hash_map_init(size_t size)
{
    /*
    if (size > 0)
    {
        */
    struct hash_map *new = malloc(sizeof(struct hash_map));
    if (!new)
        return NULL;
    struct pair_list **list;
    list = malloc(sizeof(struct pair_list *) * size);
    if (!list)
        return NULL;
    /*
    for (size_t i = 0; i < size; i++)
    {
        list[i] = malloc(sizeof(struct pair_list) * 1);
        if (!list[i])
            return NULL;
    }
    */
    new->size = size;
    new->data = list;
    for (size_t i = 0; i < size; i++)
        new->data[i] = NULL;
    return new;
    /*
}
return NULL;
*/
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (updated == NULL)
        *updated = malloc(sizeof(bool));
    if (hash_map == NULL || hash_map->size == 0)
        return *updated;
    size_t index = hash(key) % hash_map->size;
    struct pair_list *tmp = hash_map->data[index];
    while (tmp)
    {
        if (tmp->key == key)
        {
            tmp->value = value;
            *updated = true;
            return *updated;
        }
        tmp = tmp->next;
    }
    struct pair_list *new = malloc(sizeof(struct pair_list));
    if (!new)
    {
        free(new);
        return true;
    }
    new->key = key;
    new->value = value;
    new->next = NULL;
    // hash_map->data[index] = new;
    if (hash_map->data[index] == NULL)
    {
        *updated = false;
        hash_map->data[index] = new;
    }
    else
    {
        *updated = true;
        new->next = hash_map->data[index];
        hash_map->data[index] = new;
    }
    return *updated;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            struct pair_list *tmp;
            while (hash_map->data[i] != NULL)
            {
                tmp = hash_map->data[i];
                hash_map->data[i] = hash_map->data[i]->next;
                free(tmp);
            }
        }
        free(hash_map->data);
        free(hash_map);
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    size_t index = hash(key) % hash_map->size;
    if (hash_map->data[index] != NULL)
    {
        struct pair_list *tmp = hash_map->data[index];
        while (tmp)
        {
            if (tmp->key == key)
                return tmp->value;
            tmp = tmp->next;
        }
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    size_t index = hash(key) % hash_map->size;
    if (hash_map->data[index] != NULL)
    {
        struct pair_list *tmp = hash_map->data[index];
        struct pair_list *prev = hash_map->data[index];
        int i = 0;
        while (tmp)
        {
            if (tmp->key == key)
            {
                if (i == 0)
                    hash_map->data[index] = tmp->next;
                else
                    prev->next = tmp->next;
                free(tmp);
                return true;
            }
            i++;
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return false;
}
