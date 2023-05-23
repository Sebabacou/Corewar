/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_pc.c
*/

#include "corewar.h"

static size_t check_len(vm_t *vm)
{
    size_t len = 0;
    for (size_t i = 0; i != MAX_ARGS_NUMBER; i++) {
        len += get_arg_type(vm, i);
    }
    return len;
}

void define_pc(vm_t *vm, int code)
{
    if (code == 1 || code == 9 || code == 12)
        VM_PROCESS_ACTU->pc += T_DIR + 1;
    if (code == 15)
        VM_PROCESS_ACTU->pc += T_REG + 1;
    else
        VM_PROCESS_ACTU->pc += (int) check_len(vm) + 2;
}
