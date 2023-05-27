/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lld.c
*/

#include "corewar.h"

int fct_lld_ind(vm_t *vm, size_t size_arg_one)
{
    size_t one = 0;
    size_t id_reg = 0;

    one = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, size_arg_one);
    one = get_arg_value(vm, VM_PROCESS_ACTU->pc + one % IDX_MOD, 0,
    size_arg_one);
    id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one,
    VM_PROCESS_ACTU->pos_y, T_REG);
    if (id_reg > REG_NUMBER)
        return 84;
    VM_PROCESS_ACTU->reg[id_reg] = get_arg_value(vm, VM_PROCESS_ACTU->pc + one,
    0, T_REG);
    return 42;
}

int fct_lld_tdir(vm_t *vm, size_t size_arg_one)
{
    size_t one = 0;
    size_t id_reg = 0;

    one = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, size_arg_one + 2);
    id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + size_arg_one + 2,
                        VM_PROCESS_ACTU->pos_y, T_REG);
    if (id_reg > REG_NUMBER)
        return 84;
    VM_PROCESS_ACTU->reg[id_reg] = get_arg_value(vm, VM_PROCESS_ACTU->pc + one,
    0, T_REG);
    return 42;
}

int fct_lld(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 3);

    if (size_arg_one == T_DIR)
        if (fct_lld_tdir(vm, size_arg_one) == 84)
            return 84;
    if (size_arg_one == T_IND)
        if (fct_lld_ind(vm, size_arg_one) == 84)
            return 84;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 42;
}
