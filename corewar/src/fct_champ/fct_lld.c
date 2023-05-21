/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lld.c
*/

#include "corewar.h"

int fct_lld(vm_t *vm)
{
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
