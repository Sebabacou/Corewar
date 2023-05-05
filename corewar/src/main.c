/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** main.c
*/

#include "corewar.h"

int main( int argc, UNUSED char **argv)
{
    if (argc >= 2) {
        argv[1] = del_char(argv[1], '-');
        if (my_strcmp(argv[1], "h") == 0) {
            display_help();
            free(argv[1]);
            return 0;
        } else {
            free(argv[1]);
            return 84;
        }
    }
    return 84;
}
