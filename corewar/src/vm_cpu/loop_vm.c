/*
** EPITECH PROJECT, 2023
** loop_v
** File description:
** head
*/

#include "corewar.h"

static int is_alive(vm_t *vm)
{
    for (int i = 0; vm->champion[i].name != NULL; i++) {
        if (vm->champion[i].live == false)
            return i;
    }

    return -1;
}

int loop_vm(vm_t *vm)
{
    int check = -2;
    size_t cycle_max = vm->cycle_max;

    while (vm->champ_actu <= cycle_max) {
        vm->champ_actu++;
        if (vm->actual_cycle == cycle_max && cycle_max > 5) {
            check = is_alive(vm);
            vm->actual_cycle = 0;
            cycle_max += -5;
        }
        if (check != -2)
            return 0;
    }

    return 0;
}