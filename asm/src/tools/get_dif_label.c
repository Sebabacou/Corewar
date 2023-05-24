/*
** EPITECH PROJECT, 2023
** projet
** File description:
** get_dif_label
*/

#include "asm.h"

int check_label_before(t_command *node, char *buffer)
{
    char *temp_command = NULL;
    int res = 0;

    node = node->prev;
    for (;node != NULL;node = node->prev) {
        temp_command = my_clean_string(node->command,":",0);
        if (my_strcmp(temp_command, buffer) == 0) {
            free(temp_command);
            return res;
        }
        res -= get_arg_size(node);
    }
    return 1;
}

int check_label_after(t_command *node, char *buffer)
{
    char *temp_command = NULL;
    int res = 0;

    node = node->prev;
    for (;node != NULL;node = node->next) {
        temp_command = my_clean_string(node->command,":",0);
        if (my_strcmp(temp_command, buffer) == 0) {
            free(temp_command);
            return res;
        }
        res += get_arg_size(node);
    }
    return 0;
}

int get_dif_label(t_command *node, char const *buffer)
{
    int res;
    char *temp_buffer = NULL;

    temp_buffer = my_clean_string((char *)buffer, "%:", 0);
    if ((res = check_label_before(node, temp_buffer)) != 1) {
        free(temp_buffer);
        my_printf("size : %i\n", res);
        return res;
    }
    res = check_label_after(node, temp_buffer);
    my_printf("size : %i\n", res);
    return res;
}
