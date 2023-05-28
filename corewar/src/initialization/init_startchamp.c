/*
** EPITECH PROJECT, 2023
** inti start champ
** File description:
** init the begining
*/

#include "corewar.h"

void setup_start(vm_t *vm)
{
    int dif = 0;

    if (vm->nbr_champ == 0)
        return;
    dif = MEM_Y / vm->nbr_champ;
    vm->champ_actu = 0;
    VM_CHAMP_ACTU.process_actu = 0;
    for (int i = 0; i < MEM_Y; i += dif) {
        if (VM_PROCESS_ACTU->pos_x == 0 && VM_PROCESS_ACTU->pos_y == 0) {
            VM_PROCESS_ACTU->pos_x = 0;
            VM_PROCESS_ACTU->pos_y = i;
        }
        vm->champ_actu++;
    }
    return;
}
