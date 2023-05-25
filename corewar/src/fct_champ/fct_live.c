/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int fct_live(vm_t *vm)
{
    VM_CHAMP_ACTU.live = true;
    VM_CHAMP_ACTU.nbr_of_live++;
    if (VM_CHAMP_ACTU.nbr_of_live == 40) {
        vm->cycle_to_die -= CYCLE_DELTA;
        VM_CHAMP_ACTU.nbr_of_live = 0;
    }
    printf("LIVE = %s -P-> %ld\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU
    .process_actu);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
