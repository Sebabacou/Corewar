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
    size_t y = 0;

    if (nbr == -1)
        return -1;
    create_x_y_form_value((int *)&x, (int *)&y, (int)nbr);
    VM_PROCESS_ACTU->pos_y = y;
    VM_PROCESS_ACTU->pos_x = x;
    return 1;
}
