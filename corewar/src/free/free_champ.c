/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** free_champ.c
*/

#include "corewar.h"

void free_champ(champion_t *champion, size_t nbr_champ)
{
    if (champion != NULL) {
        for (size_t i = 0; i != nbr_champ + 1; i++) {
            my_free((void *) champion[i].name);
            my_free((void *) champion[i].process);
        }
        free(champion);
    }
}
