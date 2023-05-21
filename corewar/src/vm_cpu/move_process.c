/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** move_pc.c
*/

#include "corewar.h"

void move_process(vm_t *vm, int move)
{
    size_t x = move;
    size_t y = 0;

    if (x >= MEM_X) {
        y += (x / MEM_X);
        x %= MEM_X;
        y %= MEM_Y;
    }
//    printf("add_to_y = %ld\n", y);
//    y += VM_PROCESS_ACTU->pos_y;
    VM_PROCESS_ACTU->pos_x = x;
    VM_PROCESS_ACTU->pos_y = y;
}
