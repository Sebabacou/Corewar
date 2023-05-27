/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** define_pc.c
*/

#include "corewar.h"

static size_t check_len(vm_t *vm, int code)
{
    size_t len = 0;
    size_t verif = 0;

    for (size_t i = 0; i != MAX_ARGS_NUMBER; i++) {
        verif = get_arg_type(vm, i);
        if (verif == T_DIR) {
            verif = DIR_SIZE;
//            printf("DIR\n");
        }
        if ((verif == T_IND && code == 10) || (verif == T_IND && code == 11)) {
            verif = IND_SIZE;
//            printf("IND\n");
        }
//        printf("%ld | %ld\n", verif, i);
        len += verif;
    }
//    printf("len to add other = %ld\n", len + 2);
    return len + 1;
}

void define_pc(vm_t *vm, int code)
{
//    printf("--------------------------------------- NEW pc from -> %d %s\n",
//           code, op_tab[code - 1].mnemonique);
//    printf("LAST PC -> %d\n", VM_PROCESS_ACTU->pc);
    if (code == 1 || code == 9 || code == 12 || code == 15) {
        if (code == 1) {
            VM_PROCESS_ACTU->pc = create_value_form_x_y(VM_PROCESS_ACTU->pos_x,
            VM_PROCESS_ACTU->pos_y) + DIR_SIZE;
//            printf("len to add direct = %d and %ld,%ld\n", T_DIR + 1,
//                   VM_PROCESS_ACTU->pos_x, VM_PROCESS_ACTU->pos_y);
        }
        if (code == 12 || code == 9 || code == 15) {
            VM_PROCESS_ACTU->pc = create_value_form_x_y(VM_PROCESS_ACTU->pos_x,
            VM_PROCESS_ACTU->pos_y) + IND_SIZE;
//            printf("len to add index = %d\n", IND_SIZE + 1);
        }
    } else
        VM_PROCESS_ACTU->pc = create_value_form_x_y(VM_PROCESS_ACTU->pos_x,
        VM_PROCESS_ACTU->pos_y) + (int)check_len(vm, code);
    VM_PROCESS_ACTU->pc += 1;
//    printf("result -> %d", VM_PROCESS_ACTU->pc);
    int x = 0;
    int y = 0;
    create_x_y_form_value(&x, &y, VM_PROCESS_ACTU->pc);
//    printf(" = %x\n", vm->buffer[y][x]);
}
