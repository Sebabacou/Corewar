/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** display_buffer.c
*/

#include "corewar.h"

static void check_char_display(unsigned char value)
{
    if (value != 0)
        my_printf("%x|",value);
    else
        my_printf("%d|",value);
}

void display_buffer(vm_t *vm)
{
    for (size_t i = 0; i != MEM_Y; i++) {
        for (size_t y = 0; y != MEM_X; y++)
            check_char_display(vm->buffer[i][y]);
        my_printf("\n");
    }
}
