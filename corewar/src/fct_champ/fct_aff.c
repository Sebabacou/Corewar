/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_aff.c
*/

#include "corewar.h"

int fct_aff(vm_t *vm)
{
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
