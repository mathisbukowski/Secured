/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hash_func.c
*/

#include "../../include/hashtable.h"
#include <limits.h>
#include <stdio.h>

int hash(char *key, int size)
{
    unsigned int hash = OFFSET_BASIC;
    int lenght;

    if (key == NULL)
        return 84;
    lenght = my_strlen(key);
    for (int i = 0; i < lenght; i++) {
        hash ^= key[i];
        hash *= FNV_PRIME;
    }
    return ((hash >> 31) ^ (hash & INT_MAX));
}
