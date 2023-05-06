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
    vm->actual_cycle = 0;
}

int init_vm(UNUSED char **argv, vm_t *vm)
{
    if ((vm = malloc(sizeof(vm_t))) == 0)
        return 84;
    init_simple_value(vm);
    if ((vm->buffer = my_calloc(MEM_SIZE)) == NULL) {
        free(vm);
        return 84;
    }
    if (check_argv(argv, vm) != 0) {
        free_all(vm);
        return 84;
    }
    return 0;
}
