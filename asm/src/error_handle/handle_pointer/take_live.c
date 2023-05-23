/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_one_arg
*/

#include "asm.h"

int take_live(char **line,int i,data_t *data)
{
    if (line[i + 1] == NULL)
        return 1;
    if (verif_direct(line[i + 1]) == 0) {
        add_commands(data->commands,i,line);
        return 0;
    }
    return 1;
}
