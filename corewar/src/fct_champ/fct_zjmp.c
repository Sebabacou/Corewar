/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_zjmp.c
*/

#include "corewar.h"

int fct_zjmp(vm_t *vm)
{
    int temp = create_value_form_x_y(VM_PROCESS_ACTU->pos_x,
                                     VM_PROCESS_ACTU->pos_y);
    short int first_arg = 0;
    if (VM_PROCESS_ACTU->carry == 0)
        return 0;
    first_arg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 1,
                                     VM_PROCESS_ACTU->pos_y, IND_SIZE);
    temp += first_arg % IDX_MOD;
    create_x_y_form_value((int *)&VM_PROCESS_ACTU->pos_x,
                          (int *)&VM_PROCESS_ACTU->pos_y, temp);
    return 0;
}
