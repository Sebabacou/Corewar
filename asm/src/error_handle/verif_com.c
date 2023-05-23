/*
** EPITECH PROJECT, 2023
** projet
** File description:
** verif_com
*/

#include "asm.h"

int verif_com(char *buffer)
{
    if (buffer[0] == '#')
        return 0;
    return 1;
}
