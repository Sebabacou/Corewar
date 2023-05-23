/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lldi.c
*/

#include "corewar.h"

int fct_lldi(vm_t *vm)
{
    size_t arg_one_size = get_arg_type(vm, 4);
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                                     VM_PROCESS_ACTU->pos_y,arg_one_size);
    size_t arg_size_two = get_arg_type(vm, 3);
    size_t second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + arg_one_size,
                                      VM_PROCESS_ACTU->pos_y, arg_size_two);
    size_t third_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
    arg_one_size + arg_size_two, VM_PROCESS_ACTU->pos_y,T_REG);
    size_t S = get_arg_value(vm, VM_PROCESS_ACTU->pc + (first_arg % IDX_MOD), 0,
                             IND_SIZE);
    if (arg_one_size == T_REG)
        first_arg = VM_PROCESS_ACTU->reg[first_arg];
    if (arg_one_size == T_IND)
        first_arg =  get_arg_value(vm, VM_PROCESS_ACTU->pc + first_arg % IDX_MOD,
                                      0, arg_size_two);
    if (arg_size_two == T_REG)
        second_arg = VM_PROCESS_ACTU->reg[first_arg];
    S += second_arg;
    VM_PROCESS_ACTU->reg[third_arg] = get_arg_value(vm, VM_PROCESS_ACTU->pc
    + S, 0, REG_SIZE);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
