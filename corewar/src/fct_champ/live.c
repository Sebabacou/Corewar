/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int mooving_fct(vm_t *vm, int dist, int proc)
{
    int x = VM_CHAMP_ACTU.process[proc]->pos_x;
    int y = VM_CHAMP_ACTU.process[proc]->pos_y;

    for (int len = 0; len < dist; len++) {
        if (x == MEM_X - 1) {
            y++;
            x = 0;
        }
        x++;
    }

    VM_CHAMP_ACTU.process[proc]->pos_x = x;
    VM_CHAMP_ACTU.process[proc]->pos_y = y;
    return 0;
}

int fct_live(vm_t *vm, int i)
{
    VM_CHAMP_ACTU.live = true;
    return mooving_fct(vm, 5, i);

}
