/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_sti.c
*/

#include "corewar.h"

int fct_sti(vm_t *vm)
{
    size_t id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, T_REG);
    size_t size_arg_two = get_arg_type(vm, 2);
    size_t two = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 3,
                            VM_PROCESS_ACTU->pos_y, size_arg_two);
    size_t size_arg_three = get_arg_type(vm, 1);
    size_t three = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 3 + size_arg_two,
                            VM_PROCESS_ACTU->pos_y, size_arg_three);
    VM_PROCESS_ACTU->pc = 3 + size_arg_two + size_arg_three;
    move_process(vm, VM_PROCESS_ACTU->pc);
    printf("Champ = %s, %ld\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU.id);
    printf("Action = STI\n");
    printf("arg1 = %ld\n", id_reg);
    printf("arg2 = %ld\n", two);
    printf("arg3 = %ld\n", three);
    printf("-------------------------------------------\n");
    return 0;
}
