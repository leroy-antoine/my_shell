/*
** EPITECH PROJECT, 2025
** unset_env.c
** File description:
** unset env
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my_struct.h"
#include "my.h"
#include "src.h"

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

static bool free_first_elem(char **command, linked_list_t **my_env)
{
    linked_list_t *tmp = NULL;
    bool is_deleted = false;

    for (int i = 0; command[i] != NULL; i++) {
        tmp = (*my_env);
        if (my_strcmp(command[i], tmp->left) == 0) {
            (*my_env) = (*my_env)->next;
            free(tmp->left);
            free(tmp->right);
            free(tmp);
            is_deleted = true;
            break;
        }
    }
    return is_deleted;
}

static linked_list_t **delete_var(char **command, linked_list_t **my_env)
{
    linked_list_t *tmp = (*my_env);

    if (tmp == NULL)
        return NULL;
    if (free_first_elem(command, my_env))
        return my_env;
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
    delete_var(command, my_env);
    return env;
}
