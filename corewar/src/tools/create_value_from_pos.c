/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** create_value_from_pos.c
*/

#include "corewar.h"

int create_value_form_x_y(int x, int y)
{
    if (y > 0)
        x += y * MEM_X;
    return x;
}
