/*
** EPITECH PROJECT, 2023
** open file
** File description:
** open the given file
*/

#include "my.h"

char *open_file_stat(char *filepath)
{
    int fd = 0;
    char *buffer = NULL;
    struct stat buf;

    if (stat(filepath, &buf) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    if (!buffer)
        return NULL;
    fd = open(filepath,  O_RDONLY);
    if (fd == -1)
        return NULL;
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    return buffer;
}

char *open_file_nostat(char *filepath)
{
    char *buffer = malloc(sizeof(char) * 1025);
    char *result = NULL;
    int byte_read = 1024;
    int fd = open(filepath, O_RDONLY);

    while (1) {
        byte_read = read(fd, buffer, byte_read);
        buffer[byte_read] = '\0';
        if (buffer != NULL && result != NULL)
            result = my_strcat(result, buffer);
        if (result == NULL)
            result = my_strdup_shell(buffer, byte_read);
        if (result == NULL)
            return NULL;
        if (byte_read <= 0) {
            free(buffer);
            return result;
        }
    }
}
