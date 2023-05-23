/*
** EPITECH PROJECT, 2023
** new pose
** File description:
** new pose
*/

#include "corewar.h"

int *new_pos(vm_t *vm, int dist)
{
    int tab[2] = {VM_PROCESS_ACTU->pos_x, VM_PROCESS_ACTU->pos_y};

    for (int i = 0; i < dist; i++) {
        if (tab[0] + 1 < MEM_X) {
            tab[0]++;
        } else {
            tab[1]++;
            tab[0] = 0;
        }
    }
    return tab;
}
