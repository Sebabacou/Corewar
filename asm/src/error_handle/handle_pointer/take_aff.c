/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_aff
*/

#include "asm.h"

int take_aff(char **line,int i,data_t *data)
{
    if (line[i + 1] == NULL)
        return 1;
    if (verif_register(line[i + 1]) == 0) {
        add_commands(data->commands,i,line);
        return 0;
    }
    return 1;
}
