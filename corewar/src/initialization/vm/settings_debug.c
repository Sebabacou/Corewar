/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** settings_debug.c
*/

#include "corewar.h"

ssize_t manage_debug(UNUSED char **argv, UNUSED size_t index, vm_t *vm)
{
    vm->debug = true;
    return 0;
}
