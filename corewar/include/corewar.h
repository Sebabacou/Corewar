/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar.h
*/

#ifndef _COREWAR_H_
    #define _COREWAR_H_
    #define ALL 0
    #define NONE_C 1
    #define VM_CHAMP_ACTU vm->champion[vm->champ_actu]
    #define VM_PROCESS_ACTU VM_CHAMP_ACTU.process[VM_CHAMP_ACTU.process_actu]

    #include "all.h"

    typedef struct process_s {
        size_t cycle_to_wait;
        size_t pos_x;
        size_t pos_y;
    }process_t;

    typedef struct champion_s {
        size_t id;
        char *name;
        unsigned int reg[REG_NUMBER];
        int pc;
        bool carry;
        bool live;
        bool in_live;
        size_t nbr_of_process;
        size_t process_actu;
        process_t **process;
        char *buffer;
        ssize_t size_champion;
    }champion_t;

    typedef struct vm_s {
        unsigned char **buffer;
        ssize_t cycle_max;
        size_t cycle_to_die;
        size_t actual_cycle;
        size_t actual_cycle_for_die;
        champion_t *champion;
        size_t champ_actu;
        size_t nbr_champ;
    }vm_t;

    typedef struct action_s {
        unsigned int name;
        int (*fonk)(vm_t *, int proc);
    } action_t;

    typedef struct settings_flag_s {
        char *name;
        ssize_t (*fonct)(char **, size_t, vm_t *);
    }settings_flag_t;

    //========> OTHER <========//
    int check_help(char *arg);
    void free_all(vm_t *vm, size_t to_free);
    void my_free_array(void **array);
    void my_free(void* to_free);
    void free_champ(champion_t *champion, size_t nbr_champ);

    //=========> INITIALIZATION <========//
    int init_vm(char **argv, vm_t *vm);
    int check_argv(char **argv, vm_t *vm);
    ssize_t check_in_settings_flag(char **argv, vm_t *vm, size_t i);
    int init_champ(vm_t *vm);
    int read_champion(UNUSED vm_t *vm, char *path);
    void setup_start(vm_t *vm);
    int load_champion_in_vm(vm_t *vm);

    //=========> FONCT POINTER <========//
    ssize_t manage_dump(char **argv, size_t index, vm_t *vm);
    ssize_t manage_n(char **argv, size_t index, vm_t *vm);
    ssize_t manage_a(char **argv, size_t index, vm_t *vm);

    //========> DISPLAY <=======//
    void display_help(void);

    //=========> TOOLS <========//
    char *del_char(char *str, char c);
    ssize_t take_number(char *arg);
    char *my_strdup_shell(char *str, int nbr_byte);
    char *open_file_nostat(char *filepath);

    //=========> FCT-VM <========//
    void fct_live(champion_t *champion, int i);

#endif
