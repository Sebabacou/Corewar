/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** display_buffer.c
*/

#include "corewar.h"

void display_buffer(vm_t *vm)
{
    for (size_t i = 0; i != MEM_Y; i++) {
        for (size_t y = 0; y != MEM_X; y++)
            printf("%x|", vm->buffer[i][y]);
        printf("\n");
    }
}
