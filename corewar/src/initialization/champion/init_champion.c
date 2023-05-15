/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_champ.c
*/

#include "corewar.h"

static int init_process(vm_t *vm)
{
    vm->champion[vm->champ_actu].nbr_of_process = 1;
    vm->champion[vm->champ_actu].process_actu = 0;
    vm->champion[vm->champ_actu].process = malloc(sizeof(process_t *) * 2);
    if (VM_CHAMP_ACTU.process == NULL)
        return 84;
    VM_PROCESS_ACTU = malloc(sizeof(process_t));
    if (VM_PROCESS_ACTU == NULL)
        return 84;
    VM_PROCESS_ACTU->pos_x = 0;
    VM_PROCESS_ACTU->pos_y = 0;
    VM_PROCESS_ACTU->cycle_to_wait = 0;
    vm->champion[vm->champ_actu].process[vm->champion[vm->champ_actu]
    .nbr_of_process] = NULL;
    return 0;
}

static int champ_init_value(vm_t *vm)
{
    vm->champion[vm->champ_actu].name = NULL;
    vm->champion[vm->champ_actu].id = vm->champ_actu;
    vm->champion[vm->champ_actu].live = false;
    vm->champion[vm->champ_actu].carry = 0;
    vm->champion[vm->champ_actu].reg[0] = vm->champ_actu;
    vm->champion[vm->champ_actu].pc = 0;
    vm->champion[vm->champ_actu].buffer = NULL;
    return init_process(vm);
}

int init_champ(vm_t *vm)
{
    return champ_init_value(vm);
}
