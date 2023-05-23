/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_sub.c
*/

#include "corewar.h"

int fct_sub(vm_t *vm)
{
    int *tab;
    size_t size_arg_one = get_arg_type(vm, 4);

    tab = new_pos(vm, 2);
    size_t first_reg = get_arg_value(vm, tab[0], tab[1], T_REG);
    tab = new_pos(vm, 3);
    size_t second_reg = get_arg_value(vm, tab[0], tab[1], T_REG);
    tab = new_pos(vm, 4);
    size_t third_reg = get_arg_value(vm, tab[0], tab[1], T_REG);
    VM_PROCESS_ACTU->reg[third_reg] = VM_PROCESS_ACTU->reg[first_reg] - VM_PROCESS_ACTU->reg[second_reg];
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
