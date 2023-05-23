/*
** EPITECH PROJECT, 2023
** projet
** File description:
** prog_size_calculator
*/

#include "asm.h"

int prog_size_calculator(data_t *data)
{
    int res = 0;
    t_command *node = data->commands->head;

    for (;node != NULL;node = node->next) {
        res += get_arg_size(node);
    }
    return res;
}
