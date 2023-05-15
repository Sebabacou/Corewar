/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** load_champion_in_vm.c
*/

#include "corewar.h"

int load_champion_in_vm(vm_t *vm)
{
    setup_start(vm);
    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ; vm->champ_actu++)
        for (VM_CHAMP_ACTU.process_actu = 0; VM_CHAMP_ACTU.process_actu !=
        VM_CHAMP_ACTU.nbr_of_process; VM_CHAMP_ACTU.process_actu ++) {
            printf("pos_x %ld\n", VM_PROCESS_ACTU->pos_x);
            printf("pos_y %ld\n", VM_PROCESS_ACTU->pos_y);
        }
    return 0;
}
