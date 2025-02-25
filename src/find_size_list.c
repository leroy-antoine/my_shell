/*
** EPITECH PROJECT, 2025
** find_size_list.c
** File description:
** find the size of a linked list
*/

#include <stdio.h>

#include "../include/my_struct.h"

int find_size_list(linked_list_t *head)
{
    linked_list_t *tmp = head;
    int size_list = 0;

    if (tmp == NULL)
        return EXIT;
    while (tmp->next != NULL) {
        size_list += 1;
        tmp = tmp->next;
    }
    size_list += 1;
    return size_list;
}
