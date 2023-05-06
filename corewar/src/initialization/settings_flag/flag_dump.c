/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** flag_dump.c
*/

#include "corewar.h"

ssize_t manage_dump(char **argv, size_t index, vm_t *vm)
{
    vm->cycle_max = take_number(argv[index + 1]);
    if (vm->cycle_max == -1)
        return -1;
    return 0;
}
