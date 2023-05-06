/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** help_checker.c
*/

#include "corewar.h"

int check_help(char *arg)
{
    arg = del_char(arg, '-');
    if (my_strcmp(arg, "h") == 0) {
        free(arg);
        return 0;
    }
    free(arg);
    return 1;
}
