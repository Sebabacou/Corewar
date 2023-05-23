/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** fct_sti.c
*/

#include "corewar.h"

int do_sti(vm_t *vm, size_t two, size_t three, size_t id_reg)
{
    size_t x = 0;
    size_t y = 0;

    create_x_y_form_value((int *)&x, (int *)&y, VM_PROCESS_ACTU->pc + two +
    three);
    printf("STI : value %d at pos %ld,%ld -> ", vm->buffer[y][x], y, x);
    vm->buffer[y][x] = VM_PROCESS_ACTU->reg[id_reg];
    printf("%d\n", vm->buffer[x][y]);
    return 0;
}

int fct_sti(vm_t *vm)
{
    size_t id_reg = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 2,
                            VM_PROCESS_ACTU->pos_y, T_REG);
    size_t size_arg_two = get_arg_type(vm, 2);
    size_t two = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 3,
                            VM_PROCESS_ACTU->pos_y, size_arg_two);
    size_t size_arg_three = get_arg_type(vm, 1);
    size_t three = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 3 + size_arg_two,
                            VM_PROCESS_ACTU->pos_y, size_arg_three);
    size_t x = 0;
    size_t y = 0;
//    printf("%ld | %ld\n", size_arg_two, size_arg_three);

    if (size_arg_two == T_REG)
        two = VM_PROCESS_ACTU->reg[two];
    if (size_arg_two == T_IND) {
        create_x_y_form_value((int *)&x, (int *)&y, VM_PROCESS_ACTU->pc +
        two % IDX_MOD);
        two = vm->buffer[y][x];
    }
    if (size_arg_three == T_REG)
        two = VM_PROCESS_ACTU->reg[three];
    do_sti(vm, two, three, id_reg);
    move_process(vm, VM_PROCESS_ACTU->pc);
    return 0;
}
