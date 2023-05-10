/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** read_champion.c
*/

#include "corewar.h"
#include <errno.h>

int read_champion(UNUSED vm_t *vm, char *path)
{
    char *buffer = open_file_nostat(path);
//    char **name = my_str_to_word_array(path, "/");

    if (buffer == NULL)
        return 84;
//    for (size_t i = 0; name[i] != NULL; i++);
//    printf("%s|\n", buffer);
    free(buffer);
    return 0;
}
