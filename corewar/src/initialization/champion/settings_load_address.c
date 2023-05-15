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
    size_t x = 0;
    int y = 0;

    if (nbr == -1)
        return -1;
    for (int len = 0; len < nbr; len++) {
        if (x == MEM_X) {
            x = 0;
            y++;
        }
        x++;
    }
    vm->champion[vm->champ_actu].process[0]->pos_y = y - 1;
    vm->champion[vm->champ_actu].process[0]->pos_x = x - 1;
    return 1;
}
