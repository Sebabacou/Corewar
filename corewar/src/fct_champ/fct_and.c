/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_and.c
*/

#include "corewar.h"

int fct_and(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 3);
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                                     VM_PROCESS_ACTU->pos_y, size_arg_one);

    size_t arg_size_two = get_arg_type(vm, 2);
    size_t second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one,
                                      VM_PROCESS_ACTU->pos_y, arg_size_two);

    size_t arg_size_three = get_arg_type(vm, 1);
    size_t third_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one + arg_size_two,
                                      VM_PROCESS_ACTU->pos_y, arg_size_three);

    if (size_arg_one == T_IND)
        first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pc + first_arg % 
IDX_MOD, 0, T_IND);
    if (size_arg_one == T_REG)
        first_arg = VM_PROCESS_ACTU->reg[first_arg];
    if (arg_size_two == T_IND)
        second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pc + second_arg % 
IDX_MOD, 0, T_IND);
    if (arg_size_two == T_REG)
        second_arg = VM_PROCESS_ACTU->reg[second_arg];
    VM_PROCESS_ACTU->reg[third_arg] = first_arg & second_arg;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
