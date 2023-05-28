/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display_help.c
*/

#include "corewar.h"

void display_help(void)
{
    my_printf("USAGE\n");
    my_printf("./corewar [-dump nbr_cycle [[-n prog_number] [-a load_address]");
    my_printf(" prog_name] ...\n");
    my_printf("DESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_printf("execution (if the round isn't already over) with the ");
    my_printf("following format: 32 bytes/line in hexadecimal (A0BCDEFEDD..");
    my_printf(".)\n");
    my_printf("-n prog_number sets the next program's number. By default, the");
    my_printf(" first free number int the parameter order\n");
    my_printf("-a load_address sets the next program's loading address. When ");
    my_printf("no address is specified, optimize the addresses so that the ");
    my_printf("processes are as far away from each other as possible. The ");
    my_printf("addresses are MEM_SIZE modulo.\n");
    my_printf("-debug launch the vm in debug mode.\n");
}
