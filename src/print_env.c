/*
** EPITECH PROJECT, 2025
** print_env.c
** File description:
** print the env
*/

#include <unistd.h>
#include "my_struct.h"
#include "my.h"

char **print_env(__attribute_maybe_unused__ char **command,
    char **my_env, linked_list_t **env)
{
    linked_list_t *tmp = (*env);

    while (tmp != NULL) {
        if (my_strcmp(tmp->right, NO_VAL) != 0)
            mini_printf("%s=%s\n", tmp->left, tmp->right);
        else
            mini_printf("%s=\n", tmp->left);
        tmp = tmp->next;
    }
    return my_env;
}
