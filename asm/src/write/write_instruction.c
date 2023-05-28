/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** write_instruction
*/

#include "asm.h"

void write_command(t_command *node, FILE *fd)
{
    char tmp;

    for (size_t i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(node->command, op_tab[i].mnemonique) == 0) {
            tmp = (char)(i + 1);
            fwrite(&tmp, sizeof(char), 1, fd);
            return;
        }
    }
}

int write_instruction(data_t *data)
{
    FILE *fd = fopen(data->path, "a");

    if (fd == NULL)
        return 84;
    for (t_command *tmp = data->commands->head; tmp != NULL; tmp = tmp->next) {
        write_command(tmp, fd);
        write_coding_byte(tmp, fd);
        write_params(tmp, fd);
    }
    fclose(fd);
    return 0;
}
