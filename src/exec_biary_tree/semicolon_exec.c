/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** semicolon_exec
*/

#include <stdio.h>

#include "tree.h"
#include "my_struct.h"

int semicolon_exec(tree_t *tree, linked_list_t **my_env)
{
    int return_val = 0;

    if (tree->left != NULL)
        return_val = conditional_exec(tree->left->infos, my_env);
    if (tree->right != NULL)
        return conditional_exec(tree->right->infos, my_env);
    return return_val;
}
