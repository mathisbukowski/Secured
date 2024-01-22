/*
** EPITECH PROJECT, 2023
** secured
** File description:
** delete_hashtable.c
*/

#include "../../include/hashtable.h"
#include <stdlib.h>


void free_table(ht_content_t *temp)
{
    if (temp->key != NULL)
        free(temp->key);
    if (temp->value != NULL)
        free(temp->value);
    free(temp);
}

void delete_hashtable(hashtable_t *ht)
{
    ht_content_t *current;
    ht_content_t *next;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->content[i];
        while (current != NULL) {
            next = current->next;
            free_table(current);
            current = next;
        }
        ht->content[i] = NULL;
    }
    free(ht->content);
    ht->content = NULL;
    ht->len = 0;
    ht->hash_function = NULL;
    free(ht);
    ht = NULL;
}
