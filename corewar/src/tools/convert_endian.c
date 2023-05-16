/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** convert_endian.c
*/

int convert_endian(int value)
{
    return ((value & 0xFF000000) >> 24) | ((value & 0x00FF0000) >> 8) | (
    (value & 0x0000FF00) << 8) | ((value & 0x000000FF) << 24);
}
