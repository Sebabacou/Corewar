/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** check_win.c
*/

#include "corewar.h"

static void display_alive(vm_t *vm)
{
    if (VM_CHAMP_ACTU.in_live == true)
        my_printf("%s(%ld) is alive\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU.id);
    else
        my_printf("%s(%ld) is dead\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU.id);
    my_printf("nbr of live = %ld\n", vm->nbr_of_live);
}

int check_win(vm_t *vm)
{
    size_t verif = 0;
    size_t save_champ_actu = 0;
    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ;
    vm->champ_actu++) {
        if (vm->debug == true)
            display_alive(vm);
        if (VM_CHAMP_ACTU.in_live == true) {
            save_champ_actu = vm->champ_actu;
            verif++;
            VM_CHAMP_ACTU.live = false;
        }
    }
    if (verif == 1) {
        vm->champ_actu = save_champ_actu;
        my_printf("The player %d(%s)has won.\n", VM_CHAMP_ACTU.id,
        VM_CHAMP_ACTU.name); return 1;
    }
    if (verif == 0) {
        my_printf("Draw\n"); return 1;
    } return 0;
}
