/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_process.c
*/

#include "corewar.h"

int init_process(vm_t *vm)
{
    VM_CHAMP_ACTU.process = realloc(VM_CHAMP_ACTU.process, sizeof(process_t)
    * (VM_CHAMP_ACTU.nbr_of_process + 1));
    VM_CHAMP_ACTU.nbr_of_process += 1;
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
    VM_PROCESS_ACTU->reg[1] = VM_CHAMP_ACTU.id;
    for (size_t i = 2; i != REG_NUMBER + 1; i++)
        VM_PROCESS_ACTU->reg[i] = 0;
    VM_PROCESS_ACTU->pc = 0;
    vm->champion[vm->champ_actu].process[vm->champion[vm->champ_actu]
            .nbr_of_process] = NULL;
    return 0;
}
