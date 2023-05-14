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

    for (int i = 0; i != MEM_Y; i += dif) {
        vm->champion[champ].process[champ].pos_x = 0;
        vm->champion[champ].process[champ].pos_x = i;
    }

    return;
}
