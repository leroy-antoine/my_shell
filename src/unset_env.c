/*
** EPITECH PROJECT, 2025
** unset_env.c
** File description:
** unset env
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/my_struct.h"
#include "../include/my.h"
#include "../include/src.h"

static linked_list_t *check_duplicate(linked_list_t *tmp, char **command)
{
    if (tmp == NULL || tmp->next == NULL)
        return tmp;
    for (int i = 1; command[i] != NULL; i++) {
        if (my_strcmp(command[i], tmp->next->left) == 0) {
            return delete_elem(tmp, tmp->next);
        }
    }
    return tmp;
}

static void free_first_elem(char **command, linked_list_t **my_env)
{
    linked_list_t *tmp = NULL;

    if (my_env == NULL)
        return;
    for (int i = 0; command[i] != NULL; i++) {
        tmp = (*my_env);
        if (my_strcmp(command[i], tmp->left) == 0) {
            (*my_env) = (*my_env)->next;
            free(tmp->left);
            free(tmp->right);
            free(tmp);
            break;
        }
    }
}

static linked_list_t **delete_var(char **command, char **env,
    linked_list_t **my_env)
{
    linked_list_t *tmp = (*my_env);

    if (tmp == NULL)
        return NULL;
    free_first_elem(command, &tmp);
    while (tmp != NULL) {
        tmp = check_duplicate(tmp, command);
        tmp = tmp->next;
    }
    return my_env;
}

char **unset_env(char **command, char **env, linked_list_t **my_env)
{
    int size = size_command(command);

    if (my_env == NULL)
        return NULL;
    if (size < 2) {
        my_putstrd("unsetenv: Too few arguments.\n");
        return NULL;
    }
    delete_var(command, env, my_env);
    return env;
}
