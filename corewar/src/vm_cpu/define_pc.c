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
        printf("len = %ld\n", len);
    }
    printf("len_of_cmd = %ld\n", len);
    return len + 2;
}

void define_pc(vm_t *vm, int code)
{
    if (code == 1 || code == 9 || code == 12 || code == 15)
        VM_PROCESS_ACTU->pc += T_DIR + 1;
    else
        VM_PROCESS_ACTU->pc += (int)check_len(vm);
    printf("pc = %d\n", vm->buffer[0][VM_PROCESS_ACTU->pc]);
}
