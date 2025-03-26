/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** list_len
*/

#include <stddef.h>

int my_list_len(char **list)
{
    int i = 0;

    if (list == NULL)
        return 0;
    while (list[i] != NULL)
        i++;
    return i;
}
