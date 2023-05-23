/*
** EPITECH PROJECT, 2023
** projet
** File description:
** error_handle
*/

#include "asm.h"

int error_handle(int argc,char **argv, data_t *data)
{
    if (argc != 2)
        return 1;
    if (argv[1] != NULL) {
        if (my_strcmp(argv[1], "-h" ) == 0) {
            print_h();
            return 0;
        }
    }
    if ((data->champion_data = open_read_content_file(
        get_nb_line_file(argv[1]),argv[1])) != NULL) {
        if (check_all_args(data) == 1)
            return 1;
        return 0;
    }
    return 1;
}
