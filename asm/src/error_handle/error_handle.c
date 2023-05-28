/*
** EPITECH PROJECT, 2023
** projet
** File description:
** error_handle
*/

#include "asm.h"

int error_handle(int argc,char **argv, data_t *data)
{
    int nb_line;

    if (argc != 2)
        return 1;
    if ((nb_line = get_nb_line_file(argv[1])) == 0)
        return 1;
    if ((data->champion_data = open_read_content_file(
        nb_line,argv[1])) != NULL) {
        if (check_all_args(data) == 1 ||
        check_double_info(AC data->champion_data))
            return 1;
        return 0;
    }
    return 1;
}
