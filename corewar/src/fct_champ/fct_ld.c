/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_ld.c
*/
/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_sti.c
*/

#include "corewar.h"

int fct_ld(vm_t *vm)
{
    int *tab;
    size_t size_arg_one = get_arg_type(vm, 4);

    if (size_arg_one == T_DIR) {
        tab = new_pos(vm, 2);
        size_t one = get_arg_value(vm, tab[0], tab[1], T_DIR);
        tab = new_pos(vm, 4);
        size_t id_reg = get_arg_value(vm, tab[0], tab[1], T_REG);
        VM_PROCESS_ACTU->reg[id_reg] = one;
    }

    if (size_arg_one == T_IND) {
        tab = new_pos(vm, 2);
        size_t one = get_arg_value(vm, tab[0], tab[1], T_IND);
        tab = new_pos(vm, 6);
        size_t id_reg = get_arg_value(vm, tab[0], tab[1], T_REG);
        VM_PROCESS_ACTU->reg[id_reg] = vm->buffer[VM_PROCESS_ACTU->pc + one % IDX_MOD];
    }
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
