/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lldi.c
*/

#include "corewar.h"

static void do_llfi(vm_t *vm, size_t first_arg, size_t second_arg, size_t
third_arg)
{
    size_t S = get_arg_value(vm, VM_PROCESS_ACTU->pc + (first_arg % IDX_MOD), 0,
    IND_SIZE);
    S += second_arg;
    VM_PROCESS_ACTU->reg[third_arg] = get_arg_value(vm, VM_PROCESS_ACTU->pc
                                                        + S, 0, T_REG);
}

size_t fct_lldi_first(size_t arg_one_size, vm_t *vm, size_t first_arg)
{
    if (arg_one_size == T_REG)
        first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
        VM_PROCESS_ACTU->pos_y,T_REG);
    else
        first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
        VM_PROCESS_ACTU->pos_y,IND_SIZE);
    return first_arg;
}

size_t fct_lldi_second(vm_t *vm, size_t arg_size_two, size_t second_arg,
size_t arg_one_size)
{
    if (arg_size_two == T_REG)
        second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
        arg_one_size, VM_PROCESS_ACTU->pos_y, arg_size_two);
    else
        second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
        VM_PROCESS_ACTU->pos_y,IND_SIZE);
    return second_arg;
}

int fct_lldi(vm_t *vm)
{
    size_t arg_one_size = get_arg_type(vm, 3);
    size_t first_arg = 0;
    size_t arg_size_two = get_arg_type(vm, 2);
    size_t second_arg = 0;
    size_t third_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
    arg_one_size + arg_size_two, VM_PROCESS_ACTU->pos_y,T_REG);

    first_arg = fct_lldi_first(arg_one_size, vm, first_arg);
    second_arg = fct_lldi_second(vm, arg_size_two, second_arg, arg_one_size);
    if (arg_one_size == 0)
        return 84;
    if (arg_size_two == 0)
        return 84;
    if (third_arg > REG_NUMBER)
        return 84;
    do_llfi(vm, first_arg, second_arg, third_arg);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 42;
}
