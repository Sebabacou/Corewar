/*
** EPITECH PROJECT, 2022
** str n dup
** File description:
** n dup
*/

#include "corewar.h"

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
