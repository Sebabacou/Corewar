/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lld.c
*/

#include "corewar.h"

int fct_lld(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 4);
    size_t one = 0;
    size_t id_reg = 0;

    if (size_arg_one == T_DIR) {
        one = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, size_arg_one);
        id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + size_arg_one + 2,
                            VM_PROCESS_ACTU->pos_y, T_REG);
        VM_PROCESS_ACTU->reg[id_reg] = one;
    }

    if (size_arg_one == T_IND) {
        one = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, size_arg_one);
        id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one,
                            VM_PROCESS_ACTU->pos_y, T_REG);
        VM_PROCESS_ACTU->reg[id_reg] = get_arg_value(vm, VM_PROCESS_ACTU->pc + one,
                            0, T_IND);
    }
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
