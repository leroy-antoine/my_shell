/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** left_exec
*/

#include "tree.h"
#include "my_struct.h"

int left_exec(tree_t *tree, linked_list_t **my_env)
{
    return find_command(tree->infos, my_env);
}
