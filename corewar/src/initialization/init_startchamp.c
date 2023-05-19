/*
** EPITECH PROJECT, 2023
** inti start champ
** File description:
** init the begining
*/

#include "corewar.h"

void setup_start(vm_t *vm)
{
    int dif = MEM_Y / vm->nbr_champ;
    int champ = 0;

    for (int i = 0; i < MEM_Y; i += dif) {
        vm->champion[champ].process[0]->pos_x = 0;
        vm->champion[champ].process[0]->pos_y = i;
        champ++;
    }

    int i = PROG_NAME_LENGTH  + COMMENT_LENGTH;
    // for (; i != vm->champion[1].size_champion; i++)
        // printf("%x|", vm->champion[1].buffer[i]);
    printf("%ld\n", vm->champion[1].size_champion);
    printf("%d \n", i);
/*
    for (int i = 0; i != MEM_Y; i += dif) {
        vm->champion[champ].process[champ]->pos_x = 0;
        vm->champion[champ].process[champ]->pos_x = i;
    }*/
    // for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ; vm->champ_actu++)
    //     for (VM_CHAMP_ACTU.process_actu = 0; VM_CHAMP_ACTU.process_actu !=
    //     VM_CHAMP_ACTU.nbr_of_process; VM_CHAMP_ACTU.process_actu ++) {
    //         VM_PROCESS_ACTU->pos_x = 0;
    //         VM_PROCESS_ACTU->pos_y = 0;
    //     }
    return;
}
