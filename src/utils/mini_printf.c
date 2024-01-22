/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** $
*/

#include <stdarg.h>
#include "../../include/hashtable.h"
#include <stdlib.h>


int condition(va_list args, const char *format, int i)
{
    if (format[i + 1] == 'c') {
        my_putchar((char)va_arg(args, int));
        return (0);
    }
    if (format[i + 1] == 's') {
        my_putstr(va_arg(args, char *));
        return (0);
    }
    if (format[i + 1] == 'i' || format[i + 1] == 'd') {
        my_put_nbr(va_arg(args, int));
        return (0);
    }
    if (format[i + 1] == '%') {
        my_putchar(format[i]);
        return (0);
    }
    return (-1);
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int index = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            condition(args, format, i);
            i++;
        } else {
            my_putchar(format[i]);
        }
        index++;
    }
    va_end(args);
    return (index);
}
