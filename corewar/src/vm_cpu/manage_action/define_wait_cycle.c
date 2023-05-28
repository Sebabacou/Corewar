/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_wait_cycle.c
*/

#include "corewar.h"

static void display_debug(vm_t *vm, int index)
{
    size_t x = 0;
    size_t y = 0;

    my_printf("CHAMP = %s | id = %ld | ", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU
            .id);
    my_printf("process = %ld | ", VM_CHAMP_ACTU.process_actu);
    my_printf("nbr_of_process = %ld | ", VM_CHAMP_ACTU.nbr_of_process);
    my_printf("cmd = %s | ", op_tab[index].mnemonique);
    my_printf("cycle_to_wait = %ld | ", VM_PROCESS_ACTU->cycle_to_wait);
    my_printf("pc = %d | ", VM_PROCESS_ACTU->pc);
    create_x_y_form_value((int *)&x, (int *)&y, VM_PROCESS_ACTU->pc);
    my_printf("pc value = %d -> %s : %ld,%ld\n", vm->buffer[y][x],
    op_tab[vm->buffer[y][x] - 1].mnemonique, y, x);
}

static int check_cycle(vm_t *vm, int index)
{
    if (op_tab[index].code ==
    vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU->pos_x]) {
        define_pc(vm, op_tab[index].code);
        VM_PROCESS_ACTU->cycle_to_wait = op_tab[index].nbr_cycles;
        if (vm->debug == true)
            display_debug(vm, index);
        return 0;
    }
    return 1;
}

static void add_new_fonc_to_wait(vm_t *vm)
{
    for (size_t i = 0; op_tab[i].code != 0; i++) {
        if (check_cycle(vm, (int)i) == 0)
            return;
    }
    VM_PROCESS_ACTU->in_live = false;
}

int define_wait_cycle(vm_t *vm)
{
    if (VM_PROCESS_ACTU->cycle_to_wait <= -1) {
        add_new_fonc_to_wait(vm);
    }
    return 0;
}
