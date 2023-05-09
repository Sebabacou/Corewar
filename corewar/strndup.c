/*
** EPITECH PROJECT, 2022
** str n dup
** File description:
** n dup
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strndup(char const *src, int start, int finished)
{
    char *dest;
    int init = 0;
    dest = malloc(sizeof(char) * (finished - start + 1));

    if (dest == NULL)
        return NULL;
    if (src[start] == ' ')
        start++;

    while (start < finished - 1) {
        if (src[init] == '\0')
            return dest;
        dest[init] = src[start];
        init++;
        start++;
    }
    dest[init] = '\0';
    return (dest);
}

char *my_strdup_shell(char *str, int nbr_byte)
{
    char *new_str = malloc(sizeof(char) * nbr_byte + 1);
    int x = 0;

    if (new_str == NULL)
        return NULL;
    for (; x < nbr_byte; x++)
        new_str[x] = str[x];

    new_str[x] = '\0';
    return new_str;
}
