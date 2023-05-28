/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** create_pos_from_pc.c
*/

#include "corewar.h"

void create_x_y_form_value(int *x ,int *y , int value)
{
    int x_temp = value;
    int y_temp = 0;

    if (x_temp >= MEM_X) {
        y_temp += (x_temp / MEM_X);
        x_temp %= MEM_X;
        y_temp %= MEM_Y;
    }
    (*x) = x_temp;
    (*y) = y_temp;
}
