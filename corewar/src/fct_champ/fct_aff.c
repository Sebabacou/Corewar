/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_aff.c
*/

#include "corewar.h"

int fct_aff(vm_t *vm)
{
    size_t first_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, T_REG);
    int res = VM_PROCESS_ACTU->reg[first_reg] % 256;

    write(1, &res, 1);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
