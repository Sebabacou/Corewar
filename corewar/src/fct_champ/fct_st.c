/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_st.c
*/

#include "corewar.h"

int do_st(vm_t *vm, size_t two, size_t id_reg)
{
    size_t x = 0;
    size_t y = 0;

    create_x_y_form_value((int *)&x, (int *)&y, VM_PROCESS_ACTU->pc + two %
    IDX_MOD);
    vm->buffer[y][x] = id_reg;
    return 0;
}

int fct_st(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 3);
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
    VM_PROCESS_ACTU->pos_y, size_arg_one);
    size_t arg_size_two = get_arg_type(vm, 2);
    size_t second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 +
    size_arg_one, VM_PROCESS_ACTU->pos_y, T_IND);

    first_arg = VM_PROCESS_ACTU->reg[first_arg];
    if (arg_size_two == T_REG)
        VM_PROCESS_ACTU->reg[second_arg] = first_arg;
    if (arg_size_two == T_IND)
        do_st(vm, second_arg, first_arg);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
