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

    for (vm->champ_actu = 0;vm->champ_actu != vm->nbr_champ; vm->champ_actu++) {
        if (my_strcmp(VM_CHAMP_ACTU.name, DEAD) != 0) {
            save_champ_actu = vm->champ_actu;
            verif++;
        }
    }
    if (verif <= 1) {
        vm->champ_actu = save_champ_actu;
        my_printf("The player %d(%s)has won.", VM_CHAMP_ACTU.id,
                  VM_CHAMP_ACTU.name);
        return 1;
    }
    return 0;
}


static void is_alive(vm_t *vm)
{
    for (vm->champ_actu = 0; VM_CHAMP_ACTU.name != NULL; vm->champ_actu++) {
        if (my_strcmp(VM_CHAMP_ACTU.name, DEAD) == 0)
            continue;
        if (VM_CHAMP_ACTU.live == false) {
            free(VM_CHAMP_ACTU.name);
            VM_CHAMP_ACTU.name = my_strdup(DEAD);
        }
    }
}

static int check_champ(vm_t)
{

}

int loop_vm(vm_t *vm)
{
    while((ssize_t)vm->actual_cycle != vm->cycle_max) {
        for (vm->actual_cycle_for_die = 0; vm->actual_cycle_for_die !=
        vm->cycle_to_die; vm->actual_cycle++, vm->actual_cycle_for_die++) {
            //TODO : do thing with each process in each champ;
        }
        is_alive(vm);
        if (check_win(vm) == 1)
            return 1;
        vm->cycle_to_die -= CYCLE_DELTA;
    }
    return 0;
}
