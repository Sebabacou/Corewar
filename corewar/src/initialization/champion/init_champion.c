/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_champ.c
*/

#include "corewar.h"

static int champ_init_value(vm_t *vm)
{
    vm->champion[vm->champ_actu].name = NULL;
    vm->champion[vm->champ_actu].id = vm->champ_actu;
    vm->champion[vm->champ_actu].live = false;
    vm->champion[vm->champ_actu].carry = 0;
    vm->champion[vm->champ_actu].reg[0] = vm->champ_actu;
    vm->champion[vm->champ_actu].pc = 0;
    vm->champion[vm->champ_actu].nbr_of_process = 1;
    vm->champion[vm->champ_actu].buffer = NULL;
    vm->champion[vm->champ_actu].process_actu = 0;
    vm->champion[vm->champ_actu].process = malloc(sizeof(process_t *));
    if (VM_CHAMP_ACTU.process == NULL)
        return 84;
    vm->champion[vm->champ_actu].process[0] = malloc(sizeof(process_t));
    if (VM_PROCESS_ACTU == NULL)
        return 84;
    vm->champion[vm->champ_actu].process[0]->pos_x = 0;
    vm->champion[vm->champ_actu].process[0]->pos_y = 0;
    vm->champion[vm->champ_actu].process[0]->cycle_to_wait = 0;
    return 0;
}

int init_champ(vm_t *vm)
{
    return champ_init_value(vm);
}
