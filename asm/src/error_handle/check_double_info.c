/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** check_double_info
*/

#include "asm.h"

int check_double_info(char const **champion_data)
{
    int name = 0;
    int comment = 0;
    char *tmp = NULL;

    for (size_t i = 0; champion_data[i]; i++) {
        tmp = my_clean_string((char *)champion_data[i], " \t", 0);
        if (!my_strncmp(tmp, ".name", 5))
            name++;
        if (!my_strncmp(tmp, ".comment", 8))
            comment++;
        free(tmp);
        if (name > 1 || comment > 1)
            return 1;
    }
    return 0;
}
