/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** check_settings_flag.c
*/

#include "corewar.h"

static const settings_flag_t flags[] = {
        {"-dump", manage_dump},
        {"-n", manage_dump},
        {"-a", manage_dump},
        {NULL, NULL}
};

static ssize_t launch_flag(char **argv, vm_t *vm, size_t index, const
settings_flag_t *flag)
{
    if (flag->fonct != NULL)
        return flag->fonct(argv, index, vm);
    return -1;
}

ssize_t check_in_settings_flag(char **argv, vm_t *vm, size_t i)
{
    for (size_t j = 0; flags[j].name != NULL; j++)
        if (my_strcmp(flags[j].name, argv[i]) == 0)
            return launch_flag(argv, vm, i, &flags[j]);
    return -1;
}
