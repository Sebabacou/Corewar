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
//    size_t id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
//                                   VM_PROCESS_ACTU->pos_y, T_REG);
//    size_t size_arg_one = get_arg_type(vm, 4);
//    size_t one = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 3,
//                               VM_PROCESS_ACTU->pos_y, size_arg_one);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
