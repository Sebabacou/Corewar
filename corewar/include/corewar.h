/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar.h
*/

#ifndef _COREWAR_H_
    #define _COREWAR_H_

    #include "all.h"

    typedef struct champion_s {
    } champion_t ;

    typedef struct vm_s {
        unsigned char **buffer;
        size_t cycle;
    } vm_t ;

    //========> OTHER <========//
    int check_help(char *arg);

    //========> DISPLAY <=======//
    void display_help(void);

    //=========> TOOLS <========//
    char *del_char(char *str, char c);

#endif
