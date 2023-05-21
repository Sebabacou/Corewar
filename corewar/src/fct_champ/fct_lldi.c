/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_lldi.c
*/

#include "corewar.h"

int fct_lldi(vm_t *vm)
{
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
