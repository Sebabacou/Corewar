/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_process.c
*/

#include "corewar.h"

int init_process(vm_t *vm)
{
    VM_CHAMP_ACTU.nbr_of_process = 1;
    VM_CHAMP_ACTU.process_actu = 0;
    VM_CHAMP_ACTU.process = malloc(sizeof(process_t *) * 2);
    if (VM_CHAMP_ACTU.process == NULL)
        return 84;

    VM_PROCESS_ACTU = malloc(sizeof(process_t));
    if (VM_PROCESS_ACTU == NULL)
        return 84;
    VM_PROCESS_ACTU->pos_x = 0;
    VM_PROCESS_ACTU->pos_y = 0;
    VM_PROCESS_ACTU->cycle_to_wait = -1;
    VM_PROCESS_ACTU->in_live = true;
    VM_PROCESS_ACTU->carry = 0;
    VM_PROCESS_ACTU->reg[0] = vm->champ_actu;
    VM_PROCESS_ACTU->carry = 0;
    VM_PROCESS_ACTU->pc = 0;
    vm->champion[vm->champ_actu].process[vm->champion[vm->champ_actu]
            .nbr_of_process] = NULL;
    return 0;
}
