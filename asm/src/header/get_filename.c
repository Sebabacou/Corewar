/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** get_filename
*/

#include "asm.h"

char *get_filename(char const *filename)
{
    char *new_file_name = NULL;
    char **path = my_str_to_word_array(filename, "/");
    int size = my_arrsize(AC path);
    char **tmp = my_str_to_word_array(path[size - 1], ".");

    if (path == NULL || tmp == NULL)
        return NULL;
    free(path[size - 1]);
    path[size - 1] = my_strcat_free(my_strdup(tmp[0]), ".cor", 1, 0);
    if (path[size - 1] != NULL)
        new_file_name = my_array_to_str_separator(AC path, "/");
    else
        new_file_name = NULL;
    free_tab(tmp);
    free_tab(path);
    return new_file_name;
}
