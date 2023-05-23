/*
** EPITECH PROJECT, 2023
** projet
** File description:
** check_all_args
*/

#include "asm.h"
#include "pointeur_actions.h"

int see_command(char *line, data_t *data)
{
    char *temp_line = NULL;
    char **sep_line = NULL;

    temp_line = my_strdup(line);
    temp_line = clean_str(temp_line);
    if (temp_line[0] == '\n') {
        free(temp_line);
        return 0;
    }
    sep_line = my_str_to_word_array(temp_line, " ");
    if (verif_args(sep_line, data) == 1) {
        free(temp_line);
        free_tab(sep_line);
        return 1;
    }
    free_tab(sep_line);
    free(temp_line);
    return 0;
}

int check_all_args(data_t *data)
{
    for (int indice = 0;data->champion_data[indice] != NULL;indice++) {
        if (see_command(data->champion_data[indice], data) == 1)
            return 1;
    }
    return 0;
}
