/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** get_arg_value.c
*/

#include "corewar.h"

size_t get_arg_value(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (x >= MEM_X) {
            y += (x / MEM_X);
            x %= MEM_X;
            y %= MEM_Y;
        }
        result |= vm->buffer[y][x];
        if (adv + 1 < size_to_get)
            result <<= 8;
        x++;
    }
    return result;
}
