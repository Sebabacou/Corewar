/*
** EPITECH PROJECT, 2023
** projet
** File description:
** free_link
*/

#include "asm.h"

void free_labels(t_labels *labels)
{
    t_label *temp_node = labels->head;
    t_label *next = NULL;

    if (temp_node == NULL)
        return;
    for (;temp_node->next != NULL;temp_node = next) {
        next = temp_node->next;
        free(temp_node->label);
        free(temp_node);
    }
    free(temp_node->label);
    free(temp_node);
    return;
}

void free_little(t_command *node)
{
    free(node->command);
    free(node->par_one);
    if (node->par_two == NULL)
        return;
    free(node->par_two);
    if (node->par_three == NULL)
        return;
    free(node->par_three);
}

void free_commands(t_commands *commands)
{
    t_command *temp_node = commands->head;
    t_command *next = NULL;

    if (temp_node == NULL)
        return;
    for (;temp_node->next != NULL;temp_node = next) {
        next = temp_node->next;
        free_little(temp_node);
        free(temp_node);
    }
    free_little(temp_node);
    free(temp_node);
    return;
}
