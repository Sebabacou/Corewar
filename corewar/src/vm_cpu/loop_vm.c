/*
** EPITECH PROJECT, 2023
** loop_v
** File description:
** head
*/

#include "corewar.h"

static int check_win(vm_t *vm)
{
    size_t verif = 0;
    size_t save_champ_actu = 0;

    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ;
    vm->champ_actu++) {
        if (VM_CHAMP_ACTU.in_live == true) {
            save_champ_actu = vm->champ_actu;
            verif++;
        }
    }
    if (verif == 1) {
        vm->champ_actu = save_champ_actu;
        my_printf("The player %d(%s)has won.\n", VM_CHAMP_ACTU.id,
        VM_CHAMP_ACTU.name);
        return 1;
    }
    if (verif == 0) {
        my_printf("No one win\n");
        return 1;
    } return 0;
}

static void is_alive(vm_t *vm)
{
    for (vm->champ_actu = 0; VM_CHAMP_ACTU.name != NULL; vm->champ_actu++) {
        if (VM_CHAMP_ACTU.in_live == false)
            continue;
        if (VM_CHAMP_ACTU.live == false)
            VM_CHAMP_ACTU.in_live = false;
        printf("%s = %d\n", VM_CHAMP_ACTU.name, VM_CHAMP_ACTU.in_live);
    }
}

static int check_champ(vm_t *vm)
{
    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ;
    vm->champ_actu++) {
        if (VM_CHAMP_ACTU.in_live == true)
            VM_CHAMP_ACTU.carry = launch_fct_vm(vm);
    }
    return 0;
}

int loop_vm(vm_t *vm)
{
    while ((ssize_t)vm->actual_cycle != vm->cycle_max) {
        for (vm->actual_cycle_for_die = 0; vm->actual_cycle_for_die !=
        vm->cycle_to_die; vm->actual_cycle++, vm->actual_cycle_for_die++) {
            check_champ(vm);
        }
        is_alive(vm);
        if (check_win(vm) == 1)
            return 1;
        vm->cycle_to_die -= CYCLE_DELTA;
    }
    return 0;
}
