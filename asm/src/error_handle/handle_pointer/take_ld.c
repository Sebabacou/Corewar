/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_two_arg
*/

#include "asm.h"

int take_ld(char **line,int i,data_t *data)
{
    if (line[i + 1] == NULL)
        return 1;
    if (verif_direct(line[i + 1]) == 1 && verif_indirect(line[i + 1]) == 1)
        return 1;
    if (verif_register(line[i + 2]) == 0) {
        add_commands(data->commands,i,line);
        return 0;
    }
    return 1;
}
