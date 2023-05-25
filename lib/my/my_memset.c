/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** my_memset
*/

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    char *str = s;

    for (size_t i = 0; i < n; i++)
        str[i] = c;
    return s;
}
