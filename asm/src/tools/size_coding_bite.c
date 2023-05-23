/*
** EPITECH PROJECT, 2023
** projet
** File description:
** size_coding_bite
*/

#include "asm.h"

int size_coding_bite(char *command)
{
    if (my_strcmp(command, "aff") == 0)
        return 1;
    return 0;
}
