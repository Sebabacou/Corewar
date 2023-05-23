/*
** EPITECH PROJECT, 2023
** projet
** File description:
** init_all
*/

#include "asm.h"

t_labels *init_labels(void)
{
    t_labels *labels = malloc(sizeof(t_labels));

    labels->head = NULL;
    labels->tail = NULL;
    return labels;
}

t_commands *init_commands(void)
{
    t_commands *commands = malloc(sizeof(t_commands));

    commands->head = NULL;
    commands->tail = NULL;
    return commands;
}

void init_all(data_t *data)
{
    data->champion_data = NULL;
    data->error_lab = 0;
    data->com = 1;
    data->arg_size = 0;
    data->labels = init_labels();
    data->commands = init_commands();
}
