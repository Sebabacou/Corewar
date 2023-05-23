/*
** EPITECH PROJECT, 2023
** projet
** File description:
** free_all
*/

#include "asm.h"

void free_all(data_t *data)
{
    free_tab(data->champion_data);
    free_commands(data->commands);
    free(data->commands);
    free(data);
}
