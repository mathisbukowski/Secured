/*
** EPITECH PROJECT, 2023
** secured
** File description:
** ht_delete.c
*/

#include "../../include/hashtable.h"
#include <stdio.h>
#include <stdlib.h>


void check_prev(ht_content_t *current, int index,
    hashtable_t *ht, ht_content_t *prev)
{
    if (prev == NULL) {
        ht->content[index] = current->next;
    } else {
        prev->next = current->next;
    }
}

void while_cond(hashtable_t *ht, int index,
    ht_content_t *current, ht_content_t *prev)
{
    check_prev(current, index, ht, prev);
    free(current->key);
    free(current);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index;
    ht_content_t *current;
    ht_content_t *prev = NULL;

    if (ht == NULL || ht->len == 0 || key == NULL)
        return 84;
    index = ht->hash_function(key, ht->len) % ht->len;
    current = ht->content[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            while_cond(ht, index, current, prev);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
