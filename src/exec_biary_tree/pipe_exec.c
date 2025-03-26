/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** pipe_exec
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "tree.h"
#include "my_struct.h"
#include "src.h"

static int check_errors(char c, int i, char **arr)
{
    if (c == '|' && arr[i + 1] == NULL) {
        my_putstrd("Invalid null command.\n");
        return ERROR;
    }
    return SUCCESS;
}

static bool handle_error(char **arr)
{
    int error = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j]; j++)
            error = check_errors(arr[i][j], i, arr);
        if (error == ERROR)
            return true;
    }
    return false;
}

static int find_index(tree_t *tree, int index)
{
    while (tree->infos[index] != NULL && !find_the_delim(tree->infos[index]))
        index++;
    return index;
}

static int pipe_right(tree_t *tree, char **env, const int index,
    int *fd)
{
    int new_index = find_index(tree, (index + 1));
    char **arr = copy_arr(tree->infos, index, true, new_index);
    int signal = 0;
    int id = 0;

    if (arr == NULL)
        return ERROR;
    id = fork();
    if (id == 0) {
        dup2(fd[0], STDIN_FILENO);
        exit(execute_command(arr, env));
    } else {
        close(fd[0]);
        waitpid(id, &signal, 0);
    }
    free_env(arr);
    return return_val(signal);
}

static int pipe_left(tree_t *tree, char **env, int index)
{
    int id = 0;
    int signal = 0;
    char **arr = copy_arr(tree->infos, index, false, 0);
    int fd[2] = {0};

    if (arr == NULL)
        return ERROR;
    pipe(fd);
    id = fork();
    if (id == 0) {
        dup2(fd[1], STDOUT_FILENO);
        exit(execute_command(arr, env));
    } else {
        close(fd[1]);
        waitpid(id, &signal, 0);
        free_env(arr);
        return pipe_right(tree, env, index, fd);
    }
}

int pipe_exec(tree_t *tree, linked_list_t **my_env)
{
    int return_value = 0;
    int index = 0;
    char **env = create_env_from_list(my_env);

    if (env == NULL || handle_error(tree->infos))
        return ERROR;
    while (tree->infos[index] != NULL &&
        my_strcmp(tree->infos[index], "|") != 0)
        index++;
    return_value = pipe_left(tree, env, index);
    exec_binary_tree(tree->left, my_env);
    exec_binary_tree(tree->right, my_env);
    free_env(env);
    return return_value;
}
