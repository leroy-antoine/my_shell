/*
** EPITECH PROJECT, 2025
** built in cd
** File description:
** built in cd
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my_struct.h"
#include "../include/my.h"
#include "../include/src.h"

static int check_if_dir(char *path)
{
    struct stat is_dir = {0};

    if (path == NULL)
        return WRONG_COMMAND;
    if (access(path, F_OK) != 0)
        return EXIT;
    stat(path, &is_dir);
    if (!S_ISDIR(is_dir.st_mode))
        return ERROR;
    else
        return SUCCESS;
}

static char **cd_with_path(char *path, linked_list_t **my_env, char **env)
{
    int return_val = check_if_dir(path);

    if (return_val == WRONG_COMMAND)
        return NULL;
    if (return_val == ERROR) {
        my_putstrd(path);
        my_putstrd(": Not a directory.\n");
        return NULL;
    }
    if (return_val == EXIT) {
        my_putstrd(path);
        my_putstrd(": No such file or directory.\n");
        return NULL;
    }
    if (chdir(path) != 0)
        return NULL;
    return env;
}

static int change_dir(char *right)
{
    int does_it_exist = access(right, F_OK);

    if (does_it_exist != 0)
        return ERROR;
    if (chdir(right) != 0)
        return ERROR;
    return SUCCESS;
}

static char **cd_home(linked_list_t *env, char **return_val)
{
    char *home = my_strdup(HOME);
    int error = 0;

    while (env->next != NULL) {
        if (my_strcmp(env->left, home) == 0) {
            error = change_dir(env->right);
            break;
        }
        env = env->next;
    }
    if (my_strcmp(env->left, home) == 0)
        change_dir(env->right);
    free(home);
    if (error != 0)
        return NULL;
    return return_val;
}

char **built_in_cd(char **command, char **env, linked_list_t **my_env)
{
    int argc = size_command(command);
    linked_list_t *tmp = (*my_env);

    if (argc == 1)
        return cd_home(tmp, env);
    if (argc == 2)
        return cd_with_path(command[1], my_env, env);
    if (argc > 2)
        my_putstrd("cd: Too many arguments.\n");
    return NULL;
}
