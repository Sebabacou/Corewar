/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_sti
*/

#include "asm.h"

int take_sti(char **line,int i,data_t *data)
{
    if (line[i + 1] == NULL || line[i + 2] == NULL || line[i + 3] == NULL)
        return 1;
    if (verif_register(line[i + 1]) == 1)
        return 1;
    if (verif_register(line[i + 2]) == 1 && verif_indirect(line[i + 2]) == 1
    && verif_direct(line[i + 2]) == 1)
        return 1;
    if (verif_register(line[i + 3]) == 0 || verif_indirect(line[i + 3]) == 1
    || verif_direct(line[i + 3]) == 0) {
        add_commands(data->commands,i,line);
        return 0;
    }
    return 1;
}
