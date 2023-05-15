/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** read_champion.c
*/

#include "corewar.h"
#include <errno.h>

static int in_champ_buffer(char *buffer, int fd, vm_t *vm)
{
    buffer = malloc(sizeof(char) * 12288);
    if (buffer == NULL)
        return 84;
    vm->champion[vm->champ_actu].size_champion = read(fd, buffer, 6144);
    if (vm->champion[vm->champ_actu].size_champion <= -1) {
        free(buffer);
        return 84;
    }
    vm->champion[vm->champ_actu].buffer = malloc(vm->champion[vm->champ_actu]
            .size_champion + 1);
    if (vm->champion[vm->champ_actu].buffer == NULL) {
        free(buffer);
        return 84;
    }
    if (read(fd, vm->champion[vm->champ_actu].buffer,
             vm->champion[vm->champ_actu].size_champion ) <= -1) {
        free(buffer);
        return 84;
    }
    vm->champion[vm->champ_actu].size_champion = vm->champion[vm->champ_actu]
            .size_champion - (PROG_NAME_LENGTH + COMMENT_LENGTH);
    free(buffer);
    return 0;
}

static int define_name_champ(char *path, vm_t *vm)
{
    char **name = my_str_to_word_array(path, "/");
    char **final_name = NULL;
    size_t i = 0;

    for (i = 0; my_str_in_str(name[i], ".cor") != true; i++);
    final_name = my_str_to_word_array(name[i], ".");
    vm->champion[vm->champ_actu].name = my_strdup(final_name[0]);
    my_free_array((void **)name);
    my_free_array((void **)final_name);
    return 0;
}

int read_champion(UNUSED vm_t *vm, char *path)
{
    char *buffer = NULL;
    int fd = open(path, O_RDONLY);

    if (vm->champion == NULL || fd == -1)
        return 84;
    if (in_champ_buffer(buffer, fd, vm) == 84) {
        close(fd);
        return 84;
    }
    define_name_champ(path, vm);
    vm->champ_actu = 0;
    for (ssize_t i = 0; i != VM_CHAMP_ACTU
    .size_champion + PROG_NAME_LENGTH + COMMENT_LENGTH; i++)
        printf("%x",VM_CHAMP_ACTU.buffer[i]);
    close(fd);
    free(buffer);
    return 0;
}
