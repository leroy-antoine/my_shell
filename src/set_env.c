/*
** EPITECH PROJECT, 2025
** set_env.C
** File description:
** set env
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my.h"
#include "src.h"

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

    if (tmp == NULL || my_env == NULL)
        return NULL;
    while (tmp != NULL && tmp->next != NULL) {
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

static int check_alphanumeric(char *command)
{
    bool is_valid = false;

    if ((command[0] >= 'A' && command[0] <= 'Z') ||
        (command[0] >= 'a' && command[0] <= 'z') ||
        command[0] == '_')
        is_valid = true;
    if (!is_valid)
        return EXIT;
    for (int i = 1; command[i] != '\0'; i++) {
        if ((command[i] >= 'A' && command[i] <= 'Z') ||
            (command[i] >= 'a' && command[i] <= 'z'))
            continue;
        if (command[i] >= '0' && command[i] <= '9')
            continue;
        if (command[i] == '.' || command[i] == '_')
            continue;
        return ERROR;
    }
    return SUCCESS;
}

static char **check_validity(char **command, int len_command)
{
    int return_val = 0;

    if (len_command > 3) {
        my_putstrd("setenv: Too many arguments.\n");
        return NULL;
    }
    if (len_command > 1) {
        return_val = check_alphanumeric(command[1]);
        if (return_val == SUCCESS)
            return command;
        if (return_val == EXIT)
            my_putstrd("setenv: Variable name must begin with a letter.\n");
        if (return_val == ERROR)
            my_putstrd("setenv: Variable name must "
            "contain alphanumeric characters.\n");
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
