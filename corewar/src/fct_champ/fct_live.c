/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int fct_live(vm_t *vm)
{
    size_t champ = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 1,
    VM_PROCESS_ACTU->pos_y, 4);
    if (champ > vm->nbr_champ) {
        move_process(vm, VM_PROCESS_ACTU->pc);
        return 1;
    }
    vm->champion[champ - 1].live = true;
    vm->champion[champ - 1].nbr_of_live++;
    if (vm->champion[champ - 1].nbr_of_live == 40) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->champion[champ - 1].nbr_of_live = 0;
    }
    my_printf("The player %ld(%s)is alive.\n", vm->champion[champ - 1].id,
    vm->champion[champ - 1].name);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
