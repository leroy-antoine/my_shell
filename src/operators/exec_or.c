/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** exec_and.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static void error(int *status)
{
    int signal = WTERMSIG(*status);

    if (signal == 0)
        *status = WEXITSTATUS(*status);
}

int exec_or(tree_t *tree, system_t *sys)
{
    pid_t pid = 0;
    char *path = NULL;
    char **env_list = NULL;
    int status = 0;

    env_list = env_to_list(sys->env);
    if (env_list == NULL)
        return EXIT_FAILURE;
    pid = fork();
    if (pid == -1)
        return EXIT_FAILURE;
    if (pid == 0) {
        exec_command_no_fork(tree->left->command, sys, &path, env_list);
        exit(EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
    error(&status);
    if (status == 0)
        return status;
    return exec_operator(tree->right, sys);
}
