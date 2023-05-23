/*
** EPITECH PROJECT, 2023
** projet
** File description:
** reg_in_dir
*/

#include "asm.h"

int verif_register(const char *buffer)
{
    char *temp_buffer = NULL;

    if (buffer == NULL)
        return 1;
    temp_buffer = my_strdup(buffer);
    if (temp_buffer[0] != 'r') {
        free(temp_buffer);
        return 1;
    }
    temp_buffer = my_clean_string(temp_buffer, "r", 1);
    if (my_str_isnum(temp_buffer) == 1 && my_getnbr(temp_buffer) < 16) {
        free(temp_buffer);
        return 0;
    }
    free(temp_buffer);
    return 1;
}

int verif_indirect(const char *buffer)
{
    if (buffer == NULL)
        return 1;
    if (my_str_isnum(buffer) != 1 && buffer[0] == ':')
        return 0;
    if (my_str_isnum(buffer) == 1 && buffer[0] != ':')
        return 0;
    return 1;
}

int verif_direct(const char *buffer)
{
    if (buffer == NULL)
        return 1;
    if (buffer[0] == '%')
        return 0;
    return 1;
}
