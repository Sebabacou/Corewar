/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_wait_cycle.c
*/

#include "corewar.h"

static void add_new_fonc_to_wait(vm_t *vm)
{
//    printf("%d|\n", vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU->pos_x]);
    for (size_t i = 0; op_tab[i].code != 0; i++) {
//        printf("y : %ld | x : %ld\n", VM_PROCESS_ACTU->pos_y,
//               VM_PROCESS_ACTU->pos_x);
        if (op_tab[i].code ==
            vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU->pos_x]) {
            define_pc(vm, op_tab[i].code);
            VM_PROCESS_ACTU->cycle_to_wait = op_tab[i].nbr_cycles;
            printf("CHAMP = %s | id = %ld | ", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU
                    .id);
            printf("process = %ld | ", VM_CHAMP_ACTU.process_actu);
            printf("cmd = %s | ", op_tab[i].mnemonique);
            printf("cycle_to_wait = %ld | ", VM_PROCESS_ACTU->cycle_to_wait);
            printf("pc = %d | ", VM_PROCESS_ACTU->pc);
            size_t x = 0;
            size_t y = 0;
            create_x_y_form_value((int *)&x, (int *)&y, VM_PROCESS_ACTU->pc);
            printf("pc value = %d -> %s : %ld,%ld\n", vm->buffer[y][x],
                   op_tab[vm->buffer[y][x] - 1].mnemonique, y, x);
            return;
        }
    }
    VM_PROCESS_ACTU->in_live = false;
    printf("[DEAD] = %s -P-> %ld | %d\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU
    .process_actu, vm->buffer[VM_PROCESS_ACTU->pos_y][VM_PROCESS_ACTU->pos_x]);
}

int define_wait_cycle(vm_t *vm)
{
    if (VM_PROCESS_ACTU->cycle_to_wait == -1)
        add_new_fonc_to_wait(vm);
    return 0;
}
