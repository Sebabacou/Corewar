/*
** EPITECH PROJECT, 2023
** projet
** File description:
** check_label
*/

#include "asm.h"

int verif_double_label(t_command *command)
{
    t_command *node = command->next;

    for (;node != NULL;node = node->next) {
        if (my_strcmp(command->command, node->command) == 0)
            return 1;
    }
    return 0;
}

int check_label(data_t *data)
{
    t_command *node = data->commands->head;
    int res = 0;

    for (;node != NULL;node = node->next) {
        if (node->command[my_strlen(node->command) - 1] == ':')
            res = verif_double_label(node);
        if (res == 1)
            return 1;
    }
    return 0;
}
