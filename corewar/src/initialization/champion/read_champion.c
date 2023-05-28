/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** read_champion.c
*/

#include "corewar.h"
#include <errno.h>

static int in_champ_buffer(int fd, vm_t *vm)
{
    VM_CHAMP_ACTU.size_champion = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    VM_CHAMP_ACTU.buffer = malloc(VM_CHAMP_ACTU.size_champion + 1);
    if (VM_CHAMP_ACTU.buffer == NULL)
        return 84;
    if (read(fd, VM_CHAMP_ACTU.buffer,VM_CHAMP_ACTU.size_champion ) <= -1)
        return 84;
    VM_CHAMP_ACTU.size_champion = VM_CHAMP_ACTU.size_champion -
            (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
    return 0;
}

int read_champion(vm_t *vm, char *path)
{
    int fd = open(path, O_RDONLY);

    if (vm->champion == NULL || fd == -1)
        return 84;
    if (in_champ_buffer(fd, vm) == 84) {
        close(fd);
        return 84;
    }
    define_name_champ(vm);
    close(fd);
    return 0;
}
