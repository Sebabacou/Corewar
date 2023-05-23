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
    vm->champion[vm->champ_actu].in_live = true;
    vm->champion[vm->champ_actu].live = false;
    vm->champion[vm->champ_actu].buffer = NULL;
    VM_CHAMP_ACTU.process_actu = 0;
    VM_CHAMP_ACTU.nbr_of_process = 0;
    VM_CHAMP_ACTU.process = malloc(sizeof(process_t *));
    vm->champion[vm->champ_actu].id = vm->champ_actu + 1;
    return init_process(vm);
}

int init_champ(vm_t *vm)
{
    return champ_init_value(vm);
}
