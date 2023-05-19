/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int mooving_fct(vm_t *vm, int dist)
{
    int x = VM_PROCESS_ACTU->pos_x;
    int y = VM_PROCESS_ACTU->pos_y;

    for (int len = 0; len < dist; len++) {
        if (x == MEM_X - 1) {
            y++;
            x = 0;
        }
        x++;
    }
    VM_PROCESS_ACTU->pos_x = x;
    VM_PROCESS_ACTU->pos_y = y;
    return 0;
}

int fct_live(vm_t *vm)
{
    VM_CHAMP_ACTU.live = true;
    return mooving_fct(vm, 5);
}
