/*
** EPITECH PROJECT, 2025
** parse_env.c
** File description:
** parse the env to find the command in it
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"
#include "my.h"
#include "src.h"

static char *create_path(char **to_test, char *token, char *to_find)
{
    int size = my_strlen(token) + my_strlen(to_find) + 1;

    (*to_test) = malloc(sizeof(char) * size);
    if ((*to_test) == NULL)
        return NULL;
    my_strcpy((*to_test), token);
    (*to_test) = my_strcat((*to_test), to_find);
    return (*to_test);
}

static char *is_path_command(char *token, char *to_find)
{
    int fd = -1;
    char *to_test = NULL;

    token = strtok(token, "=");
    while (token != NULL && fd == -1) {
        create_path(&to_test, token, to_find);
        if (to_test == NULL)
            continue;
        fd = open(to_test, O_RDONLY);
        token = strtok(NULL, ":");
        if (fd == -1) {
            free(to_test);
            to_test = NULL;
        }
    }
    if (fd != -1)
        close(fd);
    return to_test;
}

char *parse_env_find_command(char **env, char *command)
{
    char *token = NULL;
    char *copy_env = NULL;
    char *return_val = NULL;

    if (env == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        copy_env = my_strdup(env[i]);
        token = strtok(copy_env, "\n");
        return_val = is_path_command(token, command);
        free(copy_env);
        if (return_val != NULL)
            break;
    }
    return return_val;
}
