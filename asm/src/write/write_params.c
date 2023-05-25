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

static void write_short_param(char const *param, FILE *fd, t_command *node)
{
    short nbr;

    if (my_strncmp(param, "%:", 2) == 0) {
        nbr = htobe16((short)get_dif_label(node, param));
    } else
        nbr = htobe16(my_getnbr(param));
    fwrite(&nbr, sizeof(short), 1, fd);
}

static void write_long_param(char const *param, FILE *fd, t_command *node)
{
    int nbr;

    if (my_strncmp(param, "%:", 2) == 0)
        nbr = htobe32(get_dif_label(node, param));
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
        write_short_param(param, fd, node);
        return;
    }
    if (verif_direct(param) == 0){
        write_long_param(param, fd, node);
        return;
    }
}

void write_params(t_command *node, FILE *fd)
{
    write_param(node->par_one, node, fd, 1);
    write_param(node->par_two, node, fd, 3);
    write_param(node->par_three, node, fd, 3);
}
