/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_or.c
*/

#include "corewar.h"

size_t fct_or_second(vm_t *vm, size_t arg_size_two, size_t second_arg)
{
    if (arg_size_two == T_IND)
        second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pc + second_arg %
        IDX_MOD, 0, T_IND);
    if (arg_size_two == T_REG)
        second_arg = VM_PROCESS_ACTU->reg[second_arg];
    return second_arg;
}

size_t fct_or_first(vm_t *vm, size_t size_arg_one, size_t first_arg)
{
    if (size_arg_one == T_IND)
        first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pc + first_arg %
        IDX_MOD, 0, T_IND);
    if (size_arg_one == T_REG)
        first_arg = VM_PROCESS_ACTU->reg[first_arg];

    return first_arg;
}

int fct_or(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 3);
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
    VM_PROCESS_ACTU->pos_y, size_arg_one);
    size_t arg_size_two = get_arg_type(vm, 2);
    size_t second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
    size_arg_one, VM_PROCESS_ACTU->pos_y, arg_size_two);
    size_t arg_size_three = get_arg_type(vm, 1);
    size_t third_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
    size_arg_one + arg_size_two, VM_PROCESS_ACTU->pos_y, T_REG);

    first_arg = fct_or_first(vm, size_arg_one, first_arg);
    second_arg = fct_or_second(vm, arg_size_two, second_arg);
    if (arg_size_three != T_REG)
        return 84;
    if (third_arg > REG_NUMBER)
        return 84;
    VM_PROCESS_ACTU->reg[third_arg] = first_arg || second_arg;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 42;
}
