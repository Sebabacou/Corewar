/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_name_champ.c
*/

#include "corewar.h"

int define_name_champ(vm_t *vm)
{
    size_t j = 0;

    for (size_t i = sizeof(int); VM_CHAMP_ACTU.buffer[i] != 0; i++)
        j++;
    VM_CHAMP_ACTU.name = malloc(j + 1);
    j = 0;
    for (size_t i = sizeof(int); VM_CHAMP_ACTU.buffer[i] != 0; i++) {
        VM_CHAMP_ACTU.name[j] = VM_CHAMP_ACTU.buffer[i];
        j++;
    }
    VM_CHAMP_ACTU.name[j] = '\0';
    return 0;
}
