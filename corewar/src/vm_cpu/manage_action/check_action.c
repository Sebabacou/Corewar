/*
** EPITECH PROJECT, 2023
** check action
** File description:
** check different action
*/

#include "corewar.h"

static const action_t action[] = {
        {0x01, fct_live},
        {0x02, fct_ld},
        {0x03, fct_st},
        {0x04, fct_add},
        {0x05, fct_sub},
        {0x06, fct_and},
        {0x07, fct_or},
        {0x08, fct_xor},
        {0x09, fct_zjmp},
        {0x0a, fct_ldi},
        {0x0b, fct_sti},
        {0x0c, fct_fork},
        {0x0d, fct_lld},
        {0x0e, fct_lldi},
        {0x0f, fct_lfork},
        {0x10, fct_aff},
        {0x00, NULL},
};

int verif_fonct(vm_t *vm, size_t a)
{
    if (action[a].name == vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU
    ->pos_x])
        if (action[a].fonk != NULL)
            return action[a].fonk(vm);
    return -1;
}

int check_in_tab(vm_t *vm)
{
    int test = 0;

    for (size_t a = 0; action[a].name != 0; a++) {
        test = verif_fonct(vm, a);
        if (test != -1)
            return test;
    }
    return 1;
}

ssize_t launch_fct_vm(vm_t *vm)
{
    size_t test = 0;

    if (VM_PROCESS_ACTU->in_live == true && VM_PROCESS_ACTU->cycle_to_wait ==
    0) {
        test = check_in_tab(vm);
        if (test == 42)
            VM_PROCESS_ACTU->carry = 1;
        if (test == 84)
            VM_PROCESS_ACTU->carry = 0;
    }
    VM_PROCESS_ACTU->cycle_to_wait--;
    return 0;
}
