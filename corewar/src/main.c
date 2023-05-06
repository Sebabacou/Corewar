/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main.c
*/

#include "corewar.h"

int main(UNUSED int argc, char **argv)
{
    vm_t *vm = {NULL};

    if (argv[1] != NULL && check_help(argv[1]) == 0) {
        display_help();
        return 0;
    }
    if (init_vm(argv, vm) != 0)
        return 84;
    free_all(vm);
    return 0;
}
