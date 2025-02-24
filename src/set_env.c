/*
** EPITECH PROJECT, 2025
** set_env.C
** File description:
** set env
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my_struct.h"
#include "../include/my.h"
#include "../include/src.h"

static linked_list_t **fill_env(linked_list_t *tmp, linked_list_t **my_env,
    char *left, char *right)
{
    tmp->next = malloc(sizeof(linked_list_t));
    if (tmp == NULL)
        return NULL;
    tmp->next->next = NULL;
    tmp->next->left = my_strdup(left);
    tmp->next->right = my_strdup(right);
    if (tmp->next->left || tmp->next->right == NULL)
        return NULL;
    tmp->next->head = (*my_env);
    return my_env;
}

static linked_list_t **replace_value(char *right, linked_list_t *tmp,
    linked_list_t **my_env)
{
    if (tmp->right != NULL)
        free(tmp->right);
    tmp->right = my_strdup(right);
    if (tmp->right == NULL)
        return NULL;
    return my_env;
}

static linked_list_t **add_to_list(char *left, char *right,
    linked_list_t **my_env)
{
    linked_list_t *tmp = (*my_env);

    while (tmp->next != NULL) {
        if (my_strcmp(tmp->left, left) == 0)
            return replace_value(right, tmp, my_env);
        tmp = tmp->next;
    }
    if (my_strcmp(tmp->left, left) == 0)
        return replace_value(right, tmp, my_env);
    return fill_env(tmp, my_env, left, right);
}

static void fill_right(char **right, char *empty, char **command)
{
    if (my_strcmp(empty, NO_VAL) == 0)
        (*right) = my_strdup(NO_VAL);
    else {
        (*right) = malloc(sizeof(char) * (my_strlen(command[2]) + 1));
        (*right)[0] = '\0';
    }
}

static char **add_to_env(char **command, char **env, linked_list_t **my_env,
    char *empty)
{
    char *left = malloc(sizeof(char) * (my_strlen(command[1]) + 1));
    char *right = NULL;

    if (left == NULL)
        return NULL;
    fill_right(&right, empty, command);
    left[0] = '\0';
    my_strcpy(left, command[1]);
    if (my_strcmp(empty, NO_VAL) != 0)
        my_strcpy(right, command[2]);
    if (add_to_list(left, right, my_env) == NULL)
        return NULL;
    free(left);
    free(right);
    return env;
}

static char **find_which_exec(char **command, char **env,
    linked_list_t **my_env, int len_command)
{
    if (len_command == 3)
        return add_to_env(command, env, my_env, NULL);
    if (len_command == 2)
        return add_to_env(command, env, my_env, NO_VAL);
    return NULL;
}

static char **check_validity(char **command, int len_command)
{
    if (len_command > 3) {
        my_putstrd("setenv: Too many arguments.\n");
        return NULL;
    }
    if (len_command > 1) {
        if ((command[1][0] >= 'A' && command[1][0] <= 'Z') ||
            (command[1][0] >= 'a' && command[1][0] <= 'z'))
            return command;
        my_putstrd("setenv: Variable name must begin with a letter.\n");
        return NULL;
    }
    return command;
}

char **set_env(char **command, char **env, linked_list_t **my_env)
{
    int len_command = size_command(command);

    if (check_validity(command, len_command) == NULL)
        return env;
    if (len_command > 1)
        env = find_which_exec(command, env, my_env, len_command);
    else if (len_command == 1) {
        print_env(command, env, my_env);
        return env;
    }
    return env;
}
