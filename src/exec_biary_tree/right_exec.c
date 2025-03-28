/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** right_exec
*/

#include <fcntl.h>
#include "my.h"
#include "tree.h"
#include "my_struct.h"

int right_exec(tree_t *tree, linked_list_t **my_env)
{
    int return_value = 0;
    int index = 0;
    int fd = 0;

    if (handle_errors_redirections(tree))
        return ERROR;
    fd = open(tree->right->infos[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd == -1)
        return ERROR;
    while (tree->infos[index] != NULL &&
        my_strcmp(tree->infos[index], ">") != 0)
        index++;
    return_value = right_redirection(tree, my_env, index, fd);
    exec_binary_tree(tree->left, my_env);
    exec_binary_tree(tree->right, my_env);
    return return_value;
}
