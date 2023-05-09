/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** my_free.c
*/

#include "corewar.h"

void my_free(void* to_free)
{
    if (to_free != NULL)
        free(to_free);
}

void my_free_array(void **array)
{
    if (array != NULL) {
        for (size_t i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
}
