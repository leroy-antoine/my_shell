/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** exec_binary_tree
*/

#include <stdio.h>
#include <unistd.h>

#include "tree.h"
#include "my_struct.h"

static int exec_with_separator(tree_t *tree, linked_list_t **my_env)
{
    for (int i = 0; operators[i].operators != NULL; i++)
        if (operators[i].ID == tree->redirect_type)
            return operators[i].operators(tree, my_env);
    return ERROR;
}

int exec_binary_tree(tree_t *tree, linked_list_t **my_env)
{
    int return_val = 0;
    int input = dup(STDIN_FILENO);
    int output = dup(STDOUT_FILENO);

    if (tree == NULL || my_env == NULL || tree->infos == NULL)
        return return_val;
    is_there_path(my_env);
    if (tree->redirect_type == SEMILCOLON)
        return_val = operators[SEMILCOLON].operators(tree, my_env);
    else
        return_val = exec_with_separator(tree, my_env);
    dup2(input, STDIN_FILENO);
    dup2(output, STDOUT_FILENO);
    return return_val;
}
