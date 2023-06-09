/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** write_conding_byte
*/

#include "asm.h"

static const char *function[] = {
        "live",
        "zjmp",
        "fork",
        "lfork",
};

static int get_bites(char const *param)
{
    if (param == NULL)
        return 0;
    if (verif_register(param) == 0)
        return 1;
    if (verif_direct(param) == 0)
        return 2;
    if (verif_indirect(param) == 0)
        return 3;
    return 0;
}

UNU static int verify_command_coding_byte(char const *command)
{
    for (size_t i = 0; i < _SIZETAB(function); i++) {
        if (my_strcmp(function[i], command) == 0) {
            my_printf("function : %s\n", command);
            return 1;
        }
    }
    return 0;
}

void write_coding_byte(t_command *node, FILE *fd)
{
    int bigshift = 6;
    char count = 0;

    if ((node->par_two == NULL && node->par_three == NULL) &&
    (my_strcmp(node->command, "aff") != 0))
        return;

    count += (get_bites(node->par_one) << bigshift);
    bigshift -= 2;
    count += (get_bites(node->par_two) << bigshift);
    bigshift -= 2;
    count += (get_bites(node->par_three) << bigshift);
    bigshift -= 2;
    fwrite(&count, sizeof(char), 1 , fd);
}
