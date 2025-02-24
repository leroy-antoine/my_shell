/*
** EPITECH PROJECT, 2025
** manage_env.c
** File description:
** manage_env
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"

static bool is_path(linked_list_t *my_env)
{
    while (my_env != NULL) {
        if (my_env->left == NULL)
            return false;
        if (my_strcmp(my_env->left, "PATH") == 0)
            return true;
        my_env = my_env->next;
    }
    return false;
}

static void concatenate_copy(char **to_copy, char *left,
    char *right, char **env)
{
    my_strcpy((*to_copy), left);
    my_strcat((*to_copy), "=");
    my_strcat((*to_copy), right);
}

static char *alocate_mem(char **to_copy, linked_list_t *tmp)
{
    if (tmp == NULL || tmp->right == NULL)
        return NULL;
    if (tmp->left == NULL)
        (*to_copy) = malloc(sizeof(char) *
            (my_strlen(tmp->left) + 2));
    else {
        (*to_copy) = malloc(sizeof(char) *
                (my_strlen(tmp->left) + my_strlen(tmp->right) + 2));
    }
    if ((*to_copy) == NULL)
        return NULL;
    return (*to_copy);
}

char **create_env_from_list(linked_list_t **my_env)
{
    int size_list = find_size_list(*my_env);
    linked_list_t *tmp = (*my_env);
    char **env = malloc(sizeof(char *) * (size_list + 1));
    char *to_copy = NULL;

    if (env == NULL)
        return NULL;
    if (!is_path(*(my_env)))
        return NULL;
    for (int i = 0; i < size_list; i++) {
        if (alocate_mem(&to_copy, tmp) == NULL)
            return NULL;
        concatenate_copy(&to_copy, tmp->left, tmp->right, &env[i]);
        env[i] = my_strdup(to_copy);
        free(to_copy);
        if (env[i] == NULL)
            return NULL;
        tmp = tmp->next;
    }
    env[size_list] = NULL;
    return env;
}
