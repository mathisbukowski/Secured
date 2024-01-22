/*
** EPITECH PROJECT, 2023
** secured
** File description:
** ht_insert.c
*/

#include "../../include/hashtable.h"
#include <stdlib.h>

void free_all(ht_content_t *new_content, ht_content_t *current, char *value)
{
    my_strcpy(current->value, value);
    if (new_content != NULL) {
        free(new_content->key);
        free(new_content->value);
        free(new_content);
    }
}

void var_assigne(hashtable_t *ht, char *key,
    const char *value, ht_content_t *new_content)
{
    new_content->value = my_strdup(value);
    new_content->key = my_strdup(key);
    new_content->hash_key = ht->hash_function(key, my_strlen(key));
    new_content->next = NULL;
}

void init_table(const hashtable_t *ht, int index,
    ht_content_t **new_content, ht_content_t **current)
{
    (*new_content) = malloc(sizeof(ht_content_t));
    if (*new_content == NULL)
        return;
    (*current) = ht->content[index];
}

void update_content(hashtable_t *ht, int index, ht_content_t *new_content)
{
    new_content->next = ht->content[index];
    ht->content[index] = new_content;
}

static int condition_while(ht_content_t *current, ht_content_t *new_content,
    char *key, char *value)
{
    if (my_strcmp(current->key, key) == 0) {
        free_all(new_content, current, value);
        return 0;
    }
    return 1;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index;
    ht_content_t *new_content;
    ht_content_t *current;

    if (ht == NULL || ht->len == 0 || key == NULL || value == NULL)
        return 84;
    index = ht->hash_function(key, ht->len) % ht->len;
    init_table(ht, index, &new_content, &current);
    if (new_content == NULL)
        return 84;
    var_assigne(ht, key, value, new_content);
    while (current != NULL) {
        if (condition_while(current, new_content, key, value) != 1)
            return 0;
        current = current->next;
    }
    update_content(ht, index, new_content);
    return 0;
}
