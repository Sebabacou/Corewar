/*
** EPITECH PROJECT, 2023
** projet
** File description:
** add_label
*/

#include "asm.h"

void add_values_l(t_label *node,int i,char **label)
{
    node->label = my_strdup(label[i]);
}

void add_link_list_l(t_label *node,int i, char **label,t_labels *labels)
{
    add_values_l(node,i,label);
    if (labels->head == NULL) {
        node->next = NULL;
        node->prev = NULL;
        labels->head = node;
        labels->tail = node;
        return;
    }
    node->next = NULL;
    node->prev = labels->tail;
    labels->tail->next = node;
    labels->tail = node;
    return;
}

void add_labels(t_labels *labels, int i,char **label)
{
    t_label *cell = NULL;

    cell = malloc(sizeof(t_label));
    add_link_list_l(cell,i, label, labels);
    return;
}
