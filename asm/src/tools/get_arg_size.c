/*
** EPITECH PROJECT, 2023
** projet
** File description:
** get_arg_size
*/

#include "asm.h"
#include "table_indexs.h"

int verif_indexs(int i,int y)
{
    if (i == 1) {
        if (table[y].one_par == 1)
            return 0;
        return 1;
    }
    if (i == 2) {
        if (table[y].two_par == 1)
            return 0;
        return 1;
    }
    if (i == 3) {
        if (table[y].three_par == 1)
            return 0;
        return 1;
    }
    return 1;
}

static int verif_index(t_command *node,int i)
{
    int res = 1;

    for (int y = 0; table[y].command != NULL;y++) {
        if (my_strcmp(node->command, table[y].command) == 0) {
            res = verif_indexs(i,y);
            return res;
        }
    }
    return res;
}

static int calculate_param(char *param,t_command *node, int i)
{
    if (verif_indirect(param) == 0)
        return 2;
    if (verif_direct(param) == 0 && verif_index(node,i) == 0)
        return 2;
    if (verif_direct(param) == 0)
        return 4;
    if (verif_register(param) == 0)
        return 1;
    return 0;
}

static int take_size_node(t_command *node)
{
    int res = 0;

    if (node->par_one == NULL)
        return res;
    res += calculate_param(node->par_one, node, 1);
    if (node->par_two == NULL)
        return res;
    res += calculate_param(node->par_two,node, 2);
    if (node->par_three == NULL)
        return res;
    res += calculate_param(node->par_three, node, 3);
    return res;
}

int get_arg_size(t_command *node)
{
    int res = 0;

    if (node->command == NULL
    || node->command[my_strlen(node->command) - 1] == ':')
        return res;
    if (node->par_two != NULL)
        res++;
    res++;
    res += size_coding_bite(node->command);
    res += take_size_node(node);
    return res;
}
