/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** settings_id.c
*/

#include "corewar.h"

ssize_t manage_n(char **argv, size_t index, vm_t *vm)
{
    ssize_t nbr = take_number(argv[index + 1]);
    if (nbr == -1)
        return -1;
    vm->champion[vm->champ_actu].id = nbr;
    VM_PROCESS_ACTU->reg[1] = nbr;
    return 1;
}
