/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** conditionnal_exec
*/

#include <stdbool.h>

#include "my_struct.h"
#include "tree.h"

static bool is_it_delim(const char is_delim)
{
    for (int i = 0; DELIMS[i] != '\0'; i++) {
        if (is_delim == DELIMS[i])
            return true;
    }
    return false;
}

int conditional_exec(char **infos, linked_list_t **my_env)
{
    bool delim = false;

    if (infos == NULL)
        return ERROR;
    for (int i = 0; infos[i] != NULL; i++) {
        for (int j = 0; infos[i][j] != '\0'; j++)
            delim = is_it_delim(infos[i][j]);
        if (delim) {
            return exec_binary_tree(binary_tree(infos), my_env);
        }
    }
    return find_command(infos, my_env);
}
