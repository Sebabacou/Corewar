/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** get_arg.c
*/

#include "corewar.h"

static int check_reg(size_t value, size_t arg_number)
{
    size_t mask = 0b11;
    size_t mask_reg = 0b01;
    size_t check_bits = 0;

    check_bits = (value >> (arg_number * 2)) & mask;
    if (check_bits == mask_reg)
        return true;
    return false;
}

int check_dir(size_t value, size_t arg_number)
{
    size_t mask = 0b11;
    size_t mask_dir = 0b10;
    size_t check_bits = 0;

    check_bits = (value >> (arg_number * 2)) & mask;
    if (check_bits == mask_dir)
        return true;
    return false;
}

int check_ind(size_t value, size_t arg_number)
{
    size_t mask_ind = 0b11;
    size_t check_bits = 0;

    check_bits = (value >> (arg_number * 2)) & mask_ind;
    if (check_bits == mask_ind)
        return true;
    return false;
}

int get_arg_type(vm_t *vm, size_t arg_number)
{
    size_t value = get_arg_value(vm, VM_PROCESS_ACTU->pos_x + 1,
    VM_PROCESS_ACTU->pos_y, 1);

//    printf("value = %ld\n", value);
    if (check_reg(value, arg_number) == true)
        return T_REG;
    if (check_dir(value, arg_number) == true)
        return T_DIR;
    if (check_ind(value, arg_number) == true)
        return T_IND;
    return 0;
}
