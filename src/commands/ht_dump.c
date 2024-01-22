/*
** EPITECH PROJECT, 2023
** secured
** File description:
** dump.c
*/

#include "../../include/hashtable.h"
#include <stdio.h>

void ht_dump(hashtable_t *ht)
{
    ht_content_t *current = NULL;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->content[i];
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        while (current != NULL) {
            my_putstr("> ");
            my_put_nbr(current->hash_key);
            mini_printf(" - %s\n", current->value);
            current = current->next;
        }
    }
}
