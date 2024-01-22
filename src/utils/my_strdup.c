/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strdup.c
*/

#include "../../include/hashtable.h"
#include <string.h>
#include <stdlib.h>

void conditions_strdup(char *dst, int length, const char *src)
{
    if (dst != NULL) {
        for (size_t i = 0; i < length; i++)
            dst[i] = src[i];
    }
}

char *my_strdup(const char *src)
{
    char *dst = NULL;
    size_t length = 0;

    if (src != NULL) {
        length = my_strlen((char *)src) + 1;
        dst = (char *)malloc(length * sizeof(char));
        conditions_strdup(dst, length, src);
    }
    return dst;
}
