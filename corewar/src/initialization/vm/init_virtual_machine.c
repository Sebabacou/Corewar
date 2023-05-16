/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_virtual_machine.c
*/

#include "corewar.h"

static void init_simple_value(vm_t *vm)
{
    vm->cycle_max = -1;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->actual_cycle_for_die = 0;
    vm->actual_cycle = 0;
    vm->champ_actu = 0;
}

static int init_malloc_value(vm_t *vm)
{
    vm->buffer = my_calloc((MEM_Y + 1) * sizeof(unsigned char *));
    if (vm->buffer == NULL) {
        free(vm);
        return 84;
    }
    for (size_t i = 0; i != MEM_Y; i++)
        if ((vm->buffer[i] = my_calloc(MEM_X * sizeof(unsigned  char))) ==
            NULL) {
            free(vm->buffer);
            free(vm);
            return 84;
        }
    vm->buffer[MEM_Y] = NULL;
    vm->champion = malloc(sizeof(champion_t) * (4 + 1));
    if (vm->champion == NULL) {
        free_all(vm, NONE_C);
        return 84;
    }
    return 0;
}

int init_vm(UNUSED char **argv, vm_t *vm)
{
    init_simple_value(vm);
    if (init_malloc_value(vm) == 84)
        return 84;
    if (init_champ(vm) != 0)
        return 84;
    if (check_argv(argv, vm) != 0) {
        free_all(vm, ALL);
        return 84;
    }
    vm->champ_actu = 0;
    load_champion_in_vm(vm);
    return 0;
}
