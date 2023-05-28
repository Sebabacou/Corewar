/*
** EPITECH PROJECT, 2023
** projet
** File description:
** check_labels
*/

#include "asm.h"

static void lit_free(char *temp_par,char *temp_command)
{
    free(temp_par);
    free(temp_command);
}

static int existing_label(char *par, data_t *data)
{
    t_command *node = data->commands->head;
    char *temp_par = NULL;
    char *temp_command = NULL;

    temp_par = my_clean_string(par, "%:", 0);
    if (my_str_isnum(temp_par) == 1 || temp_par[0] == '-') {
        free(temp_par);
        return 0;
    }
    for (;node != NULL;node = node->next) {
        temp_command = my_strdup(node->command);
        if (temp_command[my_strlen(temp_command) - 1] == ':')
            temp_command = my_clean_string(temp_command, ":", 1);
        if (my_strcmp(temp_command, temp_par) == 0) {
            lit_free(temp_par, temp_command);
            return 0;
        } free(temp_command);
    }
    free(temp_par);
    return 1;
}

static int check_par(t_command *node, data_t *data)
{
    if (node->par_one == NULL) return 0;
    if (verif_direct(node->par_one) == 0
    || verif_indirect(node->par_one) == 0) {
        if (existing_label(node->par_one, data) == 1)
            return 1;
    }
    if (node->par_two == NULL)
        return 0;
    if (verif_direct(node->par_two) == 0
    || verif_indirect(node->par_two) == 0) {
        if (existing_label(node->par_two, data) == 1)
            return 1;
    }
    if (node->par_three == NULL)
        return 0;
    if (verif_direct(node->par_three) == 0
    || verif_indirect(node->par_three) == 0) {
        if (existing_label(node->par_three, data) == 1)
            return 1;
    } return 0;
}

int check_labels(data_t *data)
{
    t_command *node = data->commands->head;

    for (;node != NULL;node = node->next) {
        if (check_par(node, data) == 1)
            return 1;
    }
    return 0;
}
