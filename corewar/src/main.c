/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main.c
*/

#include "corewar.h"

int main( int argc, UNUSED char **argv)
{
    if (argc < 2)
        return 84;
    if (check_help(argv[1]) == 0) {
        display_help();
        return 0;
    }
    return 84;
}
