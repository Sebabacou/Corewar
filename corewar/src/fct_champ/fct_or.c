/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_or.c
*/

#include "corewar.h"

int fct_or(vm_t *vm)
{
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
