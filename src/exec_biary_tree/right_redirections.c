/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** right_redirections
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "tree.h"
#include "my_struct.h"
#include "src.h"

void free_redirections(char **env, char **arr,
    int fd)
{
    free_env(arr);
    free_env(env);
    close(fd);
}

bool handle_errors_redirections(tree_t *tree)
{
    if (tree == NULL || tree->infos == NULL)
        return true;
    if (tree->left == NULL && tree->right == NULL) {
        my_putstrd("Missing name for redirect.\n");
        return false;
    }
    if (tree->left == NULL || tree->left->infos == NULL) {
        my_putstrd("Invalid null command.\n");
        return true;
    }
    if (tree->right == NULL || tree->right->infos == NULL) {
        my_putstrd("Missing name for redirect.\n");
        return true;
    }
    return false;
}

int right_redirection(tree_t *tree, linked_list_t **my_env,
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
        if (dup2(fd, STDOUT_FILENO) == - 1)
            exit(ERROR);
        exit(find_which_exec(my_env, arr, new_env));
    } else {
        waitpid(id, &signal, 0);
        free_redirections(new_env, arr, fd);
    }
    return return_val(signal);
}
