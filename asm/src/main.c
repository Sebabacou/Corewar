/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** main.c
*/

#include "asm.h"

int main(int argc, char **argv)
{
    data_t *data = malloc(sizeof(data_t));

    init_all(data);
    if (error_handle(argc, argv, data) == 1) {
        free_all(data);
        return 84;
    }
    prog_size_calculator(data);
    free_all(data);
    return 0;
}
