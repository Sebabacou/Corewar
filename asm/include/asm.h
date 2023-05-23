/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** asm.h
*/

#ifndef _ASM_H_
    #define _ASM_H_
    #include "all.h"


//<------------------------- link_list ------------------->

    typedef struct command {
        char *command;
        char *par_one;
        char *par_two;
        char *par_three;
        struct command *next;
        struct command *prev;
    } t_command;

    typedef struct commands {
        t_command *head;
        t_command *tail;
    } t_commands;

//<-------------------------- Principal struct ------------------------------>

    typedef struct data {
        char **champion_data;
        int error_lab;
        int com;
        int arg_size;
        t_commands *commands;
    } data_t;

    int error_handle(int argc,char **argv, data_t *data);
    int check_all_args(data_t *data);
    void print_h(void);
    int get_nb_line_file(char const *filepath);
    char **open_read_content_file(int nb_line, char const *filepath);
    void init_all(data_t *data);
    void free_all(data_t *data);
    int take_name(char **line,int i, data_t *data);
    int take_add(char **line,int i,data_t *data);
    int take_live(char **line,int i,data_t *data);
    int take_st(char **line,int i,data_t *data);
    int take_aff(char **line,int i,data_t *data);
    int take_fork(char **line,int i,data_t *data);
    int take_ld(char **line,int i,data_t *data);
    int take_ldi(char **line,int i,data_t *data);
    int take_sti(char **line,int i,data_t *data);
    int take_and(char **line,int i,data_t *data);
    char *clean_str(char *buffer);
    int verif_args(char **buffer, data_t *data);
    int verif_label(char *command);
    int verif_com(char *buffer);
    int verif_register(char *buffer);
    int verif_indirect(char *buffer);
    int verif_direct(char *buffer);
    void free_commands(t_commands *labels);
    void add_commands(t_commands *commands, int i,char **command);
    int check_labels(data_t *data);
#endif
