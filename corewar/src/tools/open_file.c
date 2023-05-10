/*
** EPITECH PROJECT, 2023
** open file
** File description:
** open the given file
*/

#include "corewar.h"

char *loop(int byte_read, int fd, char *buffer, char *result)
{
    while (1) {
        byte_read = read(fd, buffer, byte_read);
        buffer[byte_read] = '\0';
        if (buffer != NULL && result != NULL)
            result = my_strcat(result, buffer);
        if (result == NULL)
            result = my_strdup_shell(buffer, byte_read);
        if (result == NULL) {
            free(result);
            free(buffer);
            return NULL;
        }
        if (byte_read <= 0) {
            free(buffer);
            return result;
        }
        if (result != NULL)
            free(result);
        result = NULL;
    }
}

char *open_file_nostat(char *filepath)
{
    char *buffer = malloc(sizeof(char) * 1025);
    char *result = NULL;
    int byte_read = 1024;
    int fd = open(filepath, O_RDONLY);

    return loop(byte_read, fd, buffer, result);
}
