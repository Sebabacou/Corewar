/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_wait_cycle.c
*/

#include "corewar.h"

static void add_new_fonc_to_wait(vm_t *vm)
{
    for (size_t i = 0; op_tab[i].hexa_value != 0; i++)
        if (op_tab[i].hexa_value ==
        vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU->pos_x]) {
            VM_PROCESS_ACTU->cycle_to_wait =  op_tab[i].nbr_cycles;
        }
}

int define_wait_cycle(vm_t *vm)
{
    for (VM_CHAMP_ACTU.process_actu = 0; VM_CHAMP_ACTU.process_actu !=
    VM_CHAMP_ACTU.nbr_of_process; VM_CHAMP_ACTU.process_actu++) {
        if (VM_PROCESS_ACTU->cycle_to_wait == -1)
            add_new_fonc_to_wait(vm);
    }
    return 0;
}
