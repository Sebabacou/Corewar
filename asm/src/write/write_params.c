/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** write_params
*/

#include "asm.h"

static void write_reg_param(char const *param, FILE *fd)
{
    char reg = (char)my_getnbr(param);
    fwrite(&reg, sizeof(char), 1, fd);
}

static void write_short_param(char const *param, FILE *fd)
{
    short nbr;
    static int first = 0;

    if (my_strncmp(param, "%:", 2) == 0) {
        nbr = htobe16((first == 0) ? 7 : -12);
        first = 1;
    } else
        nbr = htobe16(my_getnbr(param));
    fwrite(&nbr, sizeof(short), 1, fd);
}

static void write_long_param(char const *param, FILE *fd)
{
    int nbr;

    if (my_strncmp(param, "%:", 2) == 0)
        nbr = htobe32(6);
    else
        nbr = htobe32(my_getnbr(param));
    fwrite(&nbr, sizeof(int), 1, fd);
}

void write_param(char const *param, t_command *node, FILE *fd, int num)
{
    if (param == NULL)
        return;
    if (verif_register(param) == 0) {
        write_reg_param(param, fd);
        return;
    }
    if (verif_indirect(param) == 0 || (verif_direct(param) == 0 &&
    verif_index(node, num) == 0)) {
        write_short_param(param, fd);
        return;
    }
    if (verif_direct(param) == 0){
        write_long_param(param, fd);
        return;
    }
}

void write_params(t_command *node, FILE *fd)
{
    write_param(node->par_one, node, fd, 1);
    write_param(node->par_two, node, fd, 3);
    write_param(node->par_three, node, fd, 3);
}
