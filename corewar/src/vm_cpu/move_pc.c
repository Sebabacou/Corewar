/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** move_pc.c
*/

#include "corewar.h"

void move_pc(vm_t *vm, int move)
{
    VM_PROCESS_ACTU->pos_x += move;
    if (VM_PROCESS_ACTU->pos_x >= MEM_X) {
        VM_PROCESS_ACTU->pos_y += (VM_PROCESS_ACTU->pos_x / MEM_X);
        VM_PROCESS_ACTU->pos_x %= MEM_X;
        VM_PROCESS_ACTU->pos_y %= MEM_Y;
    }
}
