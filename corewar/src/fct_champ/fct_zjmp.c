/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_zjmp.c
*/

#include "corewar.h"

int fct_zjmp(vm_t *vm)
{
    if (VM_PROCESS_ACTU->carry == 0)
        return 0;
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                                     VM_PROCESS_ACTU->pos_y, IND_SIZE);
    VM_PROCESS_ACTU->pc += first_arg % IDX_MOD;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
