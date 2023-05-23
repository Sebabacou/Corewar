/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lldi.c
*/

#include "corewar.h"

int fct_lldi(vm_t *vm)
{
//    int *tab;
//    size_t tmp = 0;
//    int dist = 0;
//
//     prend le 1er argument
//    size_t arg_size = get_arg_type(vm, 4);
//    tab = new_pos(vm, 2);
//    size_t first_arg = get_arg_value(vm, tab[0], tab[1], arg_size);
//
    // prend le deuxième et stock la position dans pos
//    tab = new_pos(vm, 2 + arg_size);
//    tmp = 2 + arg_size;
//    arg_size = get_arg_type(vm, 3);
//    size_t second_arg = get_arg_value(vm, tab[0], tab[1], arg_size);
//
//    prend le troisième argument et stock la position
//    tab = new_pos(vm, tmp + arg_size);
//    arg_size = get_arg_type(vm, 2);
//    size_t third_arg = get_arg_value(vm, tab[0], tab[1], arg_size);

    // calcul la valeur de IND_SIZE à l'addresse PC + first arg % IDX_MOD
//    dist = VM_PROCESS_ACTU->pc + first_arg;
//    tab = new_pos(vm, dist);
//    size_t S = get_arg_value(vm, tab[0], tab[1], IND_SIZE);

    // trouve la valeur final, read PC + resultat précedent % IDX_MOD et copie dans r1
//    dist = VM_PROCESS_ACTU->pc + S;
//    tab = new_pos(vm, dist);
//    size_t res = get_arg_value(vm, tab[0], tab[1], REG_SIZE);

//    VM_PROCESS_ACTU->reg[1] = res;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
