/*
** EPITECH PROJECT, 2023
** projet
** File description:
** check_size_line
*/

#include "asm.h"

int check_size_name_com(data_t *data)
{
    char *name = get_info(".name", AC data->champion_data);
    char *comment = get_info(".comment", AC data->champion_data);

    if (my_strlen(name) > 128 || my_strlen(comment) > 2048) {
        free(name);
        free(comment);
        return 1;
    }
    free(comment);
    free(name);
    return 0;
}
