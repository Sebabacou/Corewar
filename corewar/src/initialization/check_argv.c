/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** check_argv.c
*/

#include "corewar.h"

int check_argv(char **argv, vm_t *vm)
{
    ssize_t to_skip = -1;

    for (size_t i = 1; argv[i] != NULL; i++) {
        if ((to_skip = check_in_settings_flag(argv, vm , i)) > 0) {
            i += to_skip;
            continue;
        }
        if (to_skip == -1) {
            printf("%s: Not a know settings. For help use ./corewar/corewar"
            " -h.\n", argv[i]);
        }
    }
    return 0;
}
