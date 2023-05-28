/*
** EPITECH PROJECT, 2023
** projet
** File description:
** take_name
*/

#include "asm.h"

int check_name_comment(data_t *data,char **buffer,int i)
{
    if (my_strcmp(".comment", buffer[i]) == 0 && data->comment == 0) {
        data->comment = 1;
        return 0;
    }
    if (my_strcmp(".name", buffer[i]) == 0 && data->name == 0) {
        data->name = 1;
        return 0;
    }
    return 1;
}

static int detect_quote(char *buffer)
{
    for (int i = 0;buffer[i] != '\0';i++) {
        if (buffer[i] == 34 && buffer[i + 1] == '\0')
            return 1;
    }
    return 0;
}

int take_name(char **line,int i,data_t *data)
{
    int count = 0;

    if (line[i + 1] == NULL || line[i + 1][0] != 34)
        return 1;
    for (int y = 0;y <= i;y++) {
        if (line[y][0] == '#')
            return 1;
    }
    if (check_name_comment(data,line,i) == 1)
        return 1;
    i++;
    for (;line[i] != NULL;i++) {
        count++;
        if (detect_quote(line[i]) == 1) {
            data->arg_size = count;
            return 0;
        }
    }
    return 1;
}
