/*
** EPITECH PROJECT, 2023
** check action
** File description:
** check different action
*/

#include "corewar.h"

static const action_t action[] = {
        {0x01, fct_live},
        {0x02, NULL},
        {0x03, NULL},
        {0x04, NULL},
        {0x05, NULL},
        {0x06, NULL},
        {0x07, NULL},
        {0x08, NULL},
        {0x09, NULL},
        {0x0a, NULL},
        {0x0b, fct_sti},
        {0x0c, NULL},
        {0x0d, NULL},
        {0x0e, NULL},
        {0x0f, NULL},
        {0x10, NULL},
        {0, NULL},
};

int verif_fonct(vm_t *vm, size_t a)
{
    if (action[a].name == vm->buffer[VM_PROCESS_ACTU->pos_y]
    [VM_PROCESS_ACTU->pos_x])
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
    for (VM_CHAMP_ACTU.process_actu = 0; VM_CHAMP_ACTU.process_actu !=
    VM_CHAMP_ACTU.nbr_of_process; VM_CHAMP_ACTU.process_actu++) {
        if (VM_PROCESS_ACTU->in_live == true &&
        VM_PROCESS_ACTU->cycle_to_wait == 0) {
            VM_PROCESS_ACTU->carry = check_in_tab(vm);
        }
        VM_PROCESS_ACTU->cycle_to_wait--;
    }
    return 0;
}
