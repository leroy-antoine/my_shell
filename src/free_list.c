/*
** EPITECH PROJECT, 2025
** free_list.c
** File description:
** free my list
*/

#include <stdlib.h>

#include "../include/my_struct.h"

void free_list(linked_list_t **head)
{
    linked_list_t *tmp = {0};

    while ((*head) != NULL) {
        tmp = (*head)->next;
        free((*head)->left);
        free((*head)->right);
        free((*head));
        (*head) = tmp;
    }
    free((*head));
}
