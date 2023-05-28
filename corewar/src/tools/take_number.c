/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** take_number.c
*/

#include "corewar.h"

ssize_t take_number(char *arg)
{
    long res = 0;

    if (my_str_isnum(arg) != 1)
        return -1;
    res = my_getnbr(arg);
    if (res < 0)
        return -1;
    return res;
}
