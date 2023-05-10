/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** read_champion.c
*/

#include "corewar.h"
#include <errno.h>
#include <string.h>

int read_champion(UNUSED vm_t *vm, char *path)
{
//    char **name = my_str_to_word_array(path, "/");
    char *buffer = NULL;
    int fd = open(path, O_RDONLY);
    ssize_t size_to_read = 0;

    if (vm->champion == NULL || fd == -1)
        return 84;

    if ((buffer = malloc(sizeof(char) * 12288)) == NULL)
        return 84;
    if ((size_to_read = read(fd, buffer, 6144)) <= -1) {
        close(fd);
        free(buffer);
        return 84;
    }
    if ((vm->champion[vm->champ_actu].buffer = malloc(size_to_read)) ==
    NULL) {
        close(fd);
        free(buffer);
        return 84;
    }
    if (read(fd, vm->champion[vm->champ_actu].buffer, size_to_read) <= -1) {
        close(fd);
        free(buffer);
        return 84;
    }
    close(fd);
    printf("\nchamp actu = %ld\n\n", vm->champ_actu);
    for ( ssize_t i = PROG_NAME_LENGTH + COMMENT_LENGTH; i != (size_to_read -
    PROG_NAME_LENGTH + COMMENT_LENGTH); i++)
        printf("%x|", vm->champion[vm->champ_actu].buffer[i]);
//    my_free_array((void **)name);
    free(buffer);
    return 0;
}
