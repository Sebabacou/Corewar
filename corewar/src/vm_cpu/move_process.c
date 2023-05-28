/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** move_pc.c
*/

#include "corewar.h"

void move_process(vm_t *vm, int move)
{
    size_t x = 0;
    size_t y = 0;

    create_x_y_form_value((int *)&x, (int *)&y, move);
    VM_PROCESS_ACTU->pos_x = x;
    VM_PROCESS_ACTU->pos_y = y;
}
