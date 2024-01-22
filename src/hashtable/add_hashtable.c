/*
** EPITECH PROJECT, 2023
** secured
** File description:
** add_hashtable.c
*/

#include "../../include/hashtable.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_table;

    if (len < 1 || hash == NULL)
        return (NULL);
    new_table = malloc(sizeof(hashtable_t));
    if (!new_table)
        return (NULL);
    new_table->content = malloc(sizeof(ht_content_t *) * len);
    if (new_table->content == NULL){
        free(new_table);
        return NULL;
    }
    new_table->len = len;
    new_table->hash_function = hash;
    for (int i = 0; i < len; i++) {
        new_table->content[i] = NULL;
    }
    return new_table;
}
