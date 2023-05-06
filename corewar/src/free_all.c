/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** free_all.c
*/

#include "corewar.h"

void free_all(vm_t *vm)
{
    if (vm != NULL) {
        if (vm->buffer != NULL)
            free(vm->buffer);
        free(vm);
    }
}
