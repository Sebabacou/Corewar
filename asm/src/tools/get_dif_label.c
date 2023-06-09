/*
** EPITECH PROJECT, 2023
** projet
** File description:
** get_dif_label
*/

#include "asm.h"

char *clone_label(char *label)
{
    char *temp_label = my_strdup(label);
    int i = my_strlen(label) - 1;

    for (;i >= 1;i--) {
        temp_label[i] = temp_label[i - 1];
    }
    temp_label[0] = ':';
    return temp_label;
}

int verif_double_point(char *buffer)
{
    for (int i = 0;buffer[i] != '\0';i++) {
        if (buffer[i] == ':')
            return 1;
    }
    return 0;
}

int check_label_before(t_command *node, char *buffer)
{
    char *temp_command = NULL;
    int res = 0;
    t_command *temp_node = node;

    temp_node = temp_node->prev;
    for (;temp_node != NULL;temp_node = temp_node->prev) {
        temp_command = clone_label(temp_node->command);
        if (temp_command == NULL)
            return 0;
        if (my_strcmp(temp_command, buffer) == 0
        && verif_double_point(temp_node->command) == 1) {
            free(temp_command);
            return res;
        } res -= get_arg_size(temp_node);
        free(temp_command);
    } return 0;
}

int check_label_after(t_command *node, char *buffer)
{
    char *temp_command = NULL;
    int res = 0;
    t_command *temp_node = node;

    for (;temp_node != NULL;temp_node = temp_node->next) {
        temp_command = clone_label(temp_node->command);
        if (temp_command == NULL)
            return 0;
        if (my_strcmp(temp_command, buffer) == 0
        && verif_double_point(temp_node->command) == 1) {
            free(temp_command);
            return res;
        } res += get_arg_size(temp_node);
        free(temp_command);
    } return 0;
}

int get_dif_label(t_command *node, char const *buffer)
{
    int res;
    char *temp_buffer = NULL;

    temp_buffer = my_clean_string((char *)buffer, "%", 0);
    if (temp_buffer == NULL)
        return 0;
    if ((res = check_label_before(node, temp_buffer)) != 0) {
        free(temp_buffer);
        return res;
    }
    res = check_label_after(node, temp_buffer);
    free(temp_buffer);
    return res;
}
