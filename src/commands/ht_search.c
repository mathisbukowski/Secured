/*
** EPITECH PROJECT, 2023
** secured
** File description:
** search.c
*/

#include "../../include/hashtable.h"
#include <stdlib.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int act_hash;
    ht_content_t *current;

    if (ht == NULL || key == NULL)
        return NULL;
    act_hash = ht->hash_function(key, ht->len) % ht->len;
    current = ht->content[act_hash];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
