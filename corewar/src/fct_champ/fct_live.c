/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int fct_live(vm_t *vm)
{
    VM_CHAMP_ACTU.live = true;
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
