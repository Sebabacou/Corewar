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
    if (VM_CHAMP_ACTU.buffer == NULL) {
        return 84;
    }
    if (read(fd, VM_CHAMP_ACTU.buffer,VM_CHAMP_ACTU.size_champion ) <= -1) {
        return 84;
    }
    VM_CHAMP_ACTU.size_champion = VM_CHAMP_ACTU.size_champion -
            (PROG_NAME_LENGTH + COMMENT_LENGTH);
    return 0;
}

static int define_name_champ(char *path, vm_t *vm)
{
    char **name = my_str_to_word_array(path, "/");
    char **final_name = NULL;
    size_t i = 0;

    for (i = 0; my_str_in_str(name[i], ".cor") != true; i++);
    final_name = my_str_to_word_array(name[i], ".");
    VM_CHAMP_ACTU.name = my_strdup(final_name[0]);
    my_free_array((void **)name);
    my_free_array((void **)final_name);
    return 0;
}

int read_champion(UNUSED vm_t *vm, char *path)
{
    int fd = open(path, O_RDONLY);

    if (vm->champion == NULL || fd == -1)
        return 84;
    if (in_champ_buffer(fd, vm) == 84) {
        close(fd);
        return 84;
    }
    define_name_champ(path, vm);
    close(fd);
    return 0;
}
