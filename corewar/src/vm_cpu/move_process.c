/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** move_pc.c
*/

#include "corewar.h"

void move_process(vm_t *vm, int move)
{
    size_t x = VM_PROCESS_ACTU->pos_x + move;
    size_t y = VM_PROCESS_ACTU->pos_y;

    if (x >= MEM_X) {
        y += (x / MEM_X);
        x %= MEM_X;
        y %= MEM_Y;
    }
    VM_PROCESS_ACTU->pos_x = x;
    VM_PROCESS_ACTU->pos_y = y;
}
