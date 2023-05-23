/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_tree_arg
*/

#include "asm.h"

int take_st(char **line,int i,data_t *data)
{
    if (line[i + 1] == NULL || line[i + 2] == NULL)
        return 1;
    if (verif_register(line[i + 1]) == 1)
        return 1;
    if (verif_register(line[i + 2]) == 0 || verif_indirect(line[i + 2]) == 0) {
        add_commands(data->commands,i,line);
        return 0;
    }
    return 1;
}
