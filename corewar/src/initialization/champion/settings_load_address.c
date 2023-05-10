/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** settings_load_address.c
*/

#include "corewar.h"

ssize_t manage_a(char **argv, size_t index, vm_t *vm)
{
    ssize_t nbr = take_number(argv[index + 1]);
    size_t pos_x = 0;

    if (nbr == -1)
        return -1;
    for (pos_x = 0; nbr > MEM_Y; pos_x++)
        nbr -= MEM_Y;
    vm->champion[vm->champ_actu].pos_y = nbr;
    vm->champion[vm->champ_actu].pos_x = pos_x;
    return 1;
}
