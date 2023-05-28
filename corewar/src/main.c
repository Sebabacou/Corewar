/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main.c
*/

#include "corewar.h"

int main(UNUSED int argc, char **argv)
{
    vm_t *vm;

    if ((vm = my_calloc(sizeof(vm_t))) == 0)
        return 84;
    if (argv[1] != NULL && check_help(argv[1]) == 0) {
        display_help();
        my_free(vm);
        return 0;
    }
    if (init_vm(argv, vm) != 0)
        return 84;
    if (vm->nbr_champ == 0 || loop_vm(vm) == 84) {
        free_all(vm, ALL);
        return 84;
    }
    free_all(vm, ALL);
    return 0;
}
