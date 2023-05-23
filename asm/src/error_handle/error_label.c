/*
** EPITECH PROJECT, 2023
** projet
** File description:
** error_label
*/

#include "asm.h"

int verif_label(char *command)
{
    if (command[my_strlen(command) - 1] == ':') {
        return 1;
    }
    if (command[0] == '#') {
        return 1;
    }
    return 0;
}
