/*
** EPITECH PROJECT, 2023
** loop_v
** File description:
** head
*/

#include "corewar.h"

static int check_process(vm_t *vm)
{
    for (VM_CHAMP_ACTU.process_actu = 0; VM_CHAMP_ACTU.process_actu !=
    VM_CHAMP_ACTU.nbr_of_process; VM_CHAMP_ACTU.process_actu++) {
        define_wait_cycle(vm);
        launch_fct_vm(vm);
    }
    return 0;
}

static int check_champ(vm_t *vm)
{
    for (vm->champ_actu = 0; vm->champ_actu != vm->nbr_champ;
    vm->champ_actu++)
        if (VM_CHAMP_ACTU.in_live == true)
            check_process(vm);
    return 0;
}

static void is_alive(vm_t *vm)
{
    for (vm->champ_actu = 0; VM_CHAMP_ACTU.name != NULL; vm->champ_actu++) {
        if (VM_CHAMP_ACTU.in_live == false)
            continue;
        if (VM_CHAMP_ACTU.live == false)
            VM_CHAMP_ACTU.in_live = false;
    }
}

int loop_vm(vm_t *vm)
{
    if (vm->debug == true)
        display_buffer(vm);
    while ((ssize_t)vm->actual_cycle != vm->cycle_max) {
        if (vm->debug == true)
            my_printf("Cycle to die = %ld\n", vm->cycle_to_die);
        for (vm->actual_cycle_for_die = 0; vm->actual_cycle_for_die <=
        vm->cycle_to_die && (ssize_t)vm->actual_cycle != vm->cycle_max;
        vm->actual_cycle++, vm->actual_cycle_for_die++)
            check_champ(vm);
        is_alive(vm);
        if (check_win(vm) == 1) {
            return 1;
        }
    }
    return 0;
}
