/*
** EPITECH PROJECT, 2023
** projet
** File description:
** pointeur_actions
*/

#ifndef POINTEUR_ACTIONS_H_
    #define POINTEUR_ACTIONS_H_
    #include "asm.h"

    typedef struct s_error {
        char *key;
        int nbr_arg;
        int (*fonc)(char **,int,data_t *);
    } s_error;

    static const s_error table[] = {
        {".name", 0, take_name},
        {".comment", 0,take_name},
        {"live", 1,take_live},
        {"ld", 2,take_ld},
        {"st", 2,take_st},
        {"add", 3,take_add},
        {"sub", 3,take_add},
        {"and", 3,take_and},
        {"or", 3,take_and},
        {"xor", 3,take_and},
        {"zjmp", 1,take_fork},
        {"ldi", 3,take_ld},
        {"sti", 3,take_sti},
        {"fork", 1,take_fork},
        {"lld", 2,take_ld},
        {"lldi", 3,take_ldi},
        {"lfork", 1,take_fork},
        {"aff", 1,take_aff},
        {NULL, 0,NULL},
    };

#endif /* !POINTEUR_ACTIONS_H_ */
