/*
** EPITECH PROJECT, 2025
** built in cd
** File description:
** built in cd
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_struct.h"
#include "../include/my.h"
#include "../include/src.h"

static int change_dir(char *right)
{
    int does_it_exist = access(right, F_OK);

    if (does_it_exist != 0)
        return ERROR;
    if (chdir(right) != 0)
        return ERROR;
    return SUCCESS;
}

static char **cd_home(linked_list_t **env, char **return_val)
{
    char *home = my_strdup(HOME);
    int error = 0;

    while ((*env)->next != NULL) {
        if (my_strcmp((*env)->left, home) == 0) {
            error = change_dir((*env)->right);
            break;
        }
        (*env) = (*env)->next;
    }
    if (my_strcmp((*env)->left, home) == 0)
        change_dir((*env)->right);
    (*env) = (*env)->head;
    free(home);
    if (error != 0)
        return NULL;
    return NULL;
}

char **built_in_cd(char **command, char **env, linked_list_t **my_env)
{
    int argc = size_command(command);

    if (argc == 1)
        return cd_home(my_env, env);
    if (argc > 1)
        return NULL;
    return NULL;
}
