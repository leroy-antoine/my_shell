/*
** EPITECH PROJECT, 2025
** delete
** File description:
** delete
*/



#include <stdlib.h>

#include "../include/my_struct.h"
#include "../include/src.h"
#include "../include/my.h"

linked_list_t *delete_elem(linked_list_t *elem, linked_list_t *next)
{
    if (next == NULL || elem == NULL)
        return NULL;
    elem->next = next->next;
    if (next->left != NULL)
        free(next->left);
    if (next->right != NULL)
        free(next->right);
    free(next);
    return elem;
}
