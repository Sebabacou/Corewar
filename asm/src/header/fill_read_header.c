/*
** EPITECH PROJECT, 2023
** corewars
** File description:
** fill_read_header
*/

#include <endian.h>
#include <stdio.h>
#include "op.h"
#include "asm.h"

static char *get_string(char const *info)
{
    char **tmp = my_str_to_word_array(info, "\"");
    char *content;

    if (tmp == NULL)
        return NULL;
    content = my_strdup(tmp[1]);
    free_tab(tmp);
    return content;
}

char *get_info(char const *search, char const **info)
{
    int len = my_strlen(search);
    char *clean;

    for (size_t i = 0; info[i]; i++) {
        clean = my_clean_string((char *)info[i], " \t", 0);
        if (my_strncmp(search, clean, len) == 0) {
            free(clean);
            return get_string(info[i]);
        }
        free(clean);
    }
    return NULL;
}

static header_t fill_header(void)
{
    header_t header;

    my_memset(&header, 0, sizeof(header_t));
    for (size_t i = 0; i <= PROG_NAME_LENGTH; i++)
        header.prog_name[i] = '\0';
    for (size_t i = 0; i <= COMMENT_LENGTH; i++)
        header.comment[i] = '\0';
    header.magic = htobe32(COREWAR_EXEC_MAGIC);
    return header;

}

static int write_header(data_t *data, header_t header)
{
    FILE *fd = fopen(data->path, "w+");

    if (fd == NULL)
        return 84;
    fwrite(&header, sizeof(header_t), 1, fd);
    fclose(fd);
    return 0;
}

int fill_read_header(data_t *data, char const *filename)
{
    char *name = get_info(".name", AC data->champion_data);
    char *comment = get_info(".comment", AC data->champion_data);
    header_t header = fill_header();

    my_strcpy(header.prog_name, name);
    my_strcpy(header.comment, comment);
    header.prog_size = htobe32(prog_size_calculator(data));
    free(name);
    free(comment);
    if ((data->path = get_filename(filename)) == NULL)
        return 84;
    return write_header(data, header);
}
