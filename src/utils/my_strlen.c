/*
** EPITECH PROJECT, 2023
** secured
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int index;

    index = 0;
    while (str[index] != '\0'){
        index++;
    }
    return (index);
}
