/*
** EPITECH PROJECT, 2025
** exec_command.c
** File description:
** exec_ls
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_struct.h"
#include "src.h"

static char *init_find(char **command)
{
    char *to_find = NULL;

    to_find = malloc(sizeof(char) *
        my_strlen(command[0]) + 2);
    if (to_find == NULL)
        return NULL;
    to_find[0] = '/';
    to_find[1] = '\0';
    return to_find;
}

int execute_command(char **command, char **env)
{
    char *to_find = init_find(command);
    char *to_exec = NULL;

    if (to_find == NULL)
        return EXIT;
    my_strcat(to_find, command[0]);
    to_exec = parse_env_find_command(env, to_find);
    if (to_exec == NULL)
        return EXIT;
    if (execve(to_exec, &command[0], env) == -1) {
        to_find = NULL;
        free(to_find);
        return ERROR_SHELL;
    }
    return SUCCESS;
}
