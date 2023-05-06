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
    }champion_t;

    typedef struct vm_s {
        unsigned char *buffer;
        ssize_t cycle_max;
        size_t actual_cycle;
    }vm_t;

    typedef struct settings_flag_s {
        char *name;
        ssize_t (*fonct)(char **, size_t, vm_t *);
    }settings_flag_t;

    //========> OTHER <========//
    int check_help(char *arg);
    void free_all(vm_t *vm);

    //=========> INITIALIZATION <========//
    int init_vm(char **argv, vm_t *vm);
    int check_argv(char **argv, vm_t *vm);
    ssize_t check_in_settings_flag(char **argv, vm_t *vm, size_t i);

    //=========> FONCT POINTER <========//
    ssize_t manage_dump(char **argv, size_t index, vm_t *vm);

    //========> DISPLAY <=======//
    void display_help(void);

    //=========> TOOLS <========//
    char *del_char(char *str, char c);
    ssize_t take_number(char *arg);

#endif
