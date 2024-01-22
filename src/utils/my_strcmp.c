/*
** EPITECH PROJECT, 2023
** secured
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
