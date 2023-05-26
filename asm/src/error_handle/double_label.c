/*
** EPITECH PROJECT, 2023
** projet
** File description:
** double_label
*/

#include "asm.h"

static int my_str_isalphanums(char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i]; i++)
        if ((str[i] < 'a' || str[i] > 'z') &&
                (str[i] < '0' || str[i] > '9') && str[i] != '_')
            return 0;
    return 1;
}

static int verif_char(char *buffer)
{
    char *temp_buffer = my_clean_string(buffer, ":", 0);

    for (int i = 0;temp_buffer[i] != '\0';i++) {
        if (my_str_isalphanums(buffer) == 1) {
            free(temp_buffer);
            return 1;
        }
    }
    free(temp_buffer);
    return 0;
}

static int not_label(t_commands *commands)
{
    t_command *command = commands->head;
    int res = 0;

    for (;command != NULL;command = command->next) {
        if (command->command[my_strlen(command->command) - 1] == ':')
            res = verif_char(command->command);
        if (res == 1)
            return 1;
    }
    return 0;
}

int double_label(data_t *data)
{
    if (check_label(data) == 1 || not_label(data->commands) == 1)
        return 1;
    return 0;
}
