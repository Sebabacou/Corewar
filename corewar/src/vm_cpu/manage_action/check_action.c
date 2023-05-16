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
        {0x0b, NULL},
        {0x0c, NULL},
        {0x0d, NULL},
        {0x0e, NULL},
        {0x0f, NULL},
        {0x10, NULL},
        {0, NULL},
};

int verif_fonct(vm_t *vm, size_t i, size_t a)
{
    if (action[a].name == vm->buffer[VM_CHAMP_ACTU
    .process[i]->pos_y][VM_CHAMP_ACTU.process[i]->pos_x])
        if (action[a].fonk != NULL)
            return action[a].fonk(vm, (int)i);
    return -1;
}

int check_in_tab(vm_t *vm, size_t i)
{
    int test = 0;

    for (size_t a = 0; action[a].name != 0; a++) {
        printf("%x : ", action[a].name);
        printf("%x\n",vm->buffer[VM_CHAMP_ACTU.process[i]->pos_y][VM_CHAMP_ACTU
        .process[i]->pos_x]);
        test = verif_fonct(vm, i, a);
        if (test != -1)
            return test;
    }
    return 0;
}

ssize_t launch_fct_vm(vm_t *vm)
{
    for (size_t i = 0; i < VM_CHAMP_ACTU.nbr_of_process; i++) {
        if (VM_CHAMP_ACTU.process[i]->cycle_to_wait == 0) {
            check_in_tab(vm, i);
        }
        VM_CHAMP_ACTU.process[i]->cycle_to_wait--;
    }
    return 0;
}
