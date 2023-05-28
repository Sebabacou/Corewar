/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** free_all.c
*/

#include "corewar.h"

void free_all(vm_t *vm, size_t to_free)
{
    if (vm != NULL) {
        my_free_array((void *)vm->buffer);
        if (to_free != NONE_C) {
            free_champ(vm->champion, vm->champ_actu);
        }
        free(vm);
    }
}
