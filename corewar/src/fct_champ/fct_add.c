/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_add.c
*/

#include "corewar.h"

int fct_add(vm_t *vm)
{
    size_t size_arg_one = get_arg_type(vm, 4);
    size_t first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                                     VM_PROCESS_ACTU->pos_y, size_arg_one);

    size_t arg_size_two = get_arg_type(vm, 3);
    size_t second_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one,
                                      VM_PROCESS_ACTU->pos_y, arg_size_two);

    size_t arg_size_three = get_arg_type(vm, 2);
    size_t third_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2 + size_arg_one + arg_size_two,
                                      VM_PROCESS_ACTU->pos_y, arg_size_three);
    

    VM_PROCESS_ACTU->reg[third_arg] = VM_PROCESS_ACTU->reg[first_arg] + VM_PROCESS_ACTU->reg[second_arg];
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
