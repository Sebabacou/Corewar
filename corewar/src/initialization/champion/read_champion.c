/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** read_champion.c
*/

#include "corewar.h"

int read_champion(UNUSED vm_t *vm, char *path)
{
    char *buffer = NULL;
    int fd = open(path, O_RDONLY);
    size_t size_stat = 0;

    if (fd == -1)
        return 84;
    for (size_stat = 0; read(fd, buffer, 1) != -1 ; size_stat++);
    if (read(fd ,buffer, size_stat) == -1)
        return 84;
    return 0;
}
