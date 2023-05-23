/*
** EPITECH PROJECT, 2023
** projet
** File description:
** clean_str
*/

#include "asm.h"

char *cleant(char *buffer)
{
    for (int i = 0;buffer[i] != '\0';i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    return buffer;
}

char *clean_virgule(char *buffer)
{
    for (int i = 0;buffer[i] != '\0';i++) {
        if (buffer[i] == ',')
            buffer[i] = ' ';
    }
    return buffer;
}

char *clean_str(char *buffer)
{
    buffer = cleant(buffer);
    buffer = clean_virgule(buffer);
    return buffer;
}
