/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** init_champ.c
*/

#include "corewar.h"

static void champ_init_value(vm_t *vm)
{
    vm->champion[vm->champ_actu].name = NULL;
    vm->champion[vm->champ_actu].id = vm->champ_actu;
    vm->champion[vm->champ_actu].live = false;
    vm->champion[vm->champ_actu].carry = 0;
    vm->champion[vm->champ_actu].pos = 0;
    vm->champion[vm->champ_actu].reg[0] = vm->champ_actu;
    vm->champion[vm->champ_actu].pc = 0;
}

int init_champ(vm_t *vm)
{
    printf("actu champ = %ld\n", vm->champ_actu);
    champ_init_value(vm);
    if (vm->champ_actu < 4)
        vm->champ_actu++;
    return 0;
}
