/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell2-louis.langanay
** File description:
** my_cut_char
*/

#include "corewar.h"

char *del_char(char *str, char c)
{
    char *new_str = NULL;
    int j = 0;

    if (str == NULL)
        return NULL;
    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            continue;
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    return new_str;
}
