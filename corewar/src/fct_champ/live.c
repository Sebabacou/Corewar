/*
** EPITECH PROJECT, 2023
** fct live
** File description:
** fct live
*/

#include "corewar.h"

int mooving_fct(champion_t *champion, int dist, int proc)
{
    int x = champion->process[proc].pos_x;
    int y = champion->process[proc].pos_y;

    for (int len = 0; len < dist; len++) {
        if (x == MEM_X - 1) {
            y++;
            x = 0;
        }
        x++;
    }

    champion->process[proc].pos_x = x;
    champion->process[proc].pos_y = y;
    return 0;
}

void fct_live(champion_t *champion, int i)
{
    champion->live = true;
    mooving_fct(champion, 5, i);
}
