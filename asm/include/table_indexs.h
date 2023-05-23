/*
** EPITECH PROJECT, 2023
** projet
** File description:
** table_indexs
*/

#ifndef TABLE_INDEXS_H_
    #define TABLE_INDEXS_H_
    #include "asm.h"

    typedef struct s_index {
        char *command;
        int one_par;
        int two_par;
        int three_par;
    } s_index;

    static const s_index table[] = {
        {"zjmp", 1, 0, 0},
        {"ldi", 1,1, 0},
        {"sti", 0, 1, 1},
        {"fork", 1, 0, 0},
        {"lfork", 1, 0, 0},
        {NULL, 0, 0, 0},
    };

#endif /* !TABLE_INDEXS_H_ */
