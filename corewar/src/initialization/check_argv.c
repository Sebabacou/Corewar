/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** check_argv.c
*/

#include "corewar.h"

static int check_champ(char *arg, vm_t *vm)
{
    if (my_str_in_str(arg, ".cor") == 1) {
        read_champion(vm, arg);
        if (vm->nbr_champ < 4) {
            vm->champ_actu++;
            vm->nbr_champ++;
        }
        init_champ(vm);
        return 1;
    }
    return 0;
}

int check_argv(char **argv, vm_t *vm)
{
    ssize_t to_skip = -1;

    for (size_t i = 1; argv[i] != NULL; i++) {
        if ((to_skip = check_in_settings_flag(argv, vm , i)) >= 0) {
            i += to_skip;
            continue;
        }
        if (check_champ(argv[i], vm) == 1)
            continue;
        if (to_skip == -1) {
            my_printf("%s: Not a know settings. For help use ./corewar/corewar"
                      " -h.\n", argv[i]);
        }
    }
    return 0;
}
