/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** load_champion_in_vm.c
*/

#include "corewar.h"

static void put_the_champ(vm_t *vm)
{
    size_t pos = PROG_NAME_LENGTH + COMMENT_LENGTH;
    size_t stop = VM_CHAMP_ACTU.size_champion + PROG_NAME_LENGTH +
            COMMENT_LENGTH;
    VM_CHAMP_ACTU.process_actu = 0;
    for (size_t y = VM_PROCESS_ACTU->pos_y; y != MEM_Y && pos < stop; y++) {
        for (size_t x = 0; x != MEM_X && pos < stop; x++, pos++) {
            vm->buffer[y][x] = VM_CHAMP_ACTU.buffer[pos];
        }
    }
}

int load_champion_in_vm(vm_t *vm)
{
    setup_start(vm);
    vm->champ_actu = 0;
    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ; vm->champ_actu++)
        put_the_champ(vm);
    return 0;
}
