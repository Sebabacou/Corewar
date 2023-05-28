/*
** EPITECH PROJECT, 2023
** projet
** File description:
** add_command
*/

#include "asm.h"

static void add_values(t_command *node,int i,char **command)
{
    node->command = my_strdup(command[i]);
    node->par_one = NULL;
    node->par_two = NULL;
    node->par_three = NULL;
    if (command[i + 1] == NULL
    || node->command[my_strlen(node->command) - 1] == ':')
        return;
    node->par_one = my_strdup(command[i + 1]);
    if (command[i + 2] == NULL || command[i + 2][0] == '#')
        return;
    node->par_two = my_strdup(command[i + 2]);
    if (command[i + 3] == NULL || command[i + 2][0] == '#')
        return;
    node->par_three = my_strdup(command[i + 3]);
}

static void add_link_list(t_command *node,int i,
char **command,t_commands *commands)
{
    add_values(node,i,command);
    if (commands->head == NULL) {
        node->next = NULL;
        node->prev = NULL;
        commands->head = node;
        commands->tail = node;
        return;
    }
    node->next = NULL;
    node->prev = commands->tail;
    commands->tail->next = node;
    commands->tail = node;
    return;
}

void add_commands(t_commands *commands, int i,char **command)
{
    t_command *cell = NULL;

    cell = malloc(sizeof(t_command));
    add_link_list(cell,i, command, commands);
    return;
}
