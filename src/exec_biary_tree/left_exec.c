/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** left_exec
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "tree.h"
#include "my_struct.h"
#include "src.h"

static int left_redirection(tree_t *tree, linked_list_t **my_env,
    int index, int fd)
{
    int id = 0;
    int signal = 0;
    char **arr = copy_arr(tree->infos, index, false, 0);
    char **new_env = create_env_from_list(my_env);

    if (arr == NULL || new_env == NULL)
        return ERROR;
    id = fork();
    if (id == 0) {
        if (dup2(fd, STDIN_FILENO) == - 1)
            exit(ERROR);
        exit(find_which_exec(my_env, arr, new_env));
    } else {
        waitpid(id, &signal, 0);
        free_redirections(new_env, arr, fd);
    }
    return return_val(signal);
}

int left_exec(tree_t *tree, linked_list_t **my_env)
{
    int return_value = 0;
    int index = 0;
    int fd = 0;

    if (handle_errors_redirections(tree))
        return ERROR;
    fd = open(tree->right->infos[0], O_RDONLY);
    if (fd == -1)
        return ERROR;
    while (tree->infos[index] != NULL &&
        my_strcmp(tree->infos[index], "<") != 0)
        index++;
    return_value = left_redirection(tree, my_env, index, fd);
    exec_binary_tree(tree->left, my_env);
    exec_binary_tree(tree->right, my_env);
    return return_value;
}
