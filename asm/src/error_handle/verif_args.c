/*
** EPITECH PROJECT, 2023
** projet
** File description:
** verif_args
*/

#include "asm.h"
#include "pointeur_actions.h"

static int make_pointer(char *buffer,data_t *data, int i,char **full_command)
{
    int (*fonc)(char **, int,data_t *);

    for (int y = 0; table[y].key != NULL; y++) {
        if (my_strcmp(table[y].key ,buffer) == 0) {
            fonc = table[y].fonc;
            data->arg_size = table[y].nbr_arg;
            return fonc(full_command, i,data);
        }
    }
    return 1;
}

static int loop_arg(char **buffer, data_t *data, int i)
{
    if (verif_label(buffer[i]) == 1 && data->error_lab == 0) {
        data->error_lab = 1;
        add_commands(data->commands,i,buffer);
        return 0;
    }
    if (verif_com(buffer[i]) == 0 && data->com == 0)
        return 0;
    if (make_pointer(buffer[i], data, i, buffer) == 0 && data->com == 1) {
        data->com = 0;
        return 0;
    }
    if (verif_com(buffer[i]) == 0 && data->com == 1)
        return 0;
    return 1;
}

int verif_args(char **buffer, data_t *data)
{
    if (buffer == NULL)
        return 0;
    data->arg_size = 0;
    data->com = 1;
    data->error_lab = 0;
    data->comment = 0;
    data->name = 0;
    for (int i = 0;buffer[i] != NULL;i++) {
        if (data->com == 0)
            return 0;
        if (loop_arg(buffer, data, i) == 1) {
            return 1;
        }
        if (verif_label(buffer[i]) == 0) {
            i += data->arg_size;
        }
    }
    return 0;
}
