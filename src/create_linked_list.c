/*
** EPITECH PROJECT, 2025
** create_linked_list.c
** File description:
** linked_list
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "../include/my_struct.h"
#include "../include/my.h"

static linked_list_t *fill_node(linked_list_t *my_env, char **env, int i)
{
    char *left = strtok(env[i], "=");
    char *right = strtok(NULL, "\n");

    my_env->left = my_strdup(left);
    if (my_env->left == NULL)
        return NULL;
    my_env->right = my_strdup(right);
    if (my_env->right == NULL) {
        free(my_env->right);
        return NULL;
    }
    return my_env;
}

static linked_list_t **init_next(linked_list_t **my_env, char **env,
    linked_list_t *tmp)
{
    for (int i = 1; env[i] != NULL; i++) {
        (*my_env)->next = malloc(sizeof(linked_list_t));
        if ((*my_env)->next == NULL)
            return NULL;
        (*my_env) = (*my_env)->next;
        if (fill_node(*(my_env), env, i) == NULL)
            return NULL;
        (*my_env)->head = tmp;
    }
    (*my_env)->next = NULL;
    (*my_env) = (*my_env)->head;
    return my_env;
}

linked_list_t *create_linked_list(linked_list_t **my_env, char **env)
{
    linked_list_t *tmp = NULL;

    (*my_env) = malloc(sizeof(linked_list_t));
    if ((*my_env) == NULL)
        return NULL;
    if (fill_node((*my_env), env, 0) == NULL)
        return NULL;
    tmp = (*my_env);
    my_env = init_next(my_env, env, tmp);
    if (my_env == NULL)
        return NULL;
    (*my_env)->head = tmp;
    (*my_env) = (*my_env)->head;
    return (*my_env);
}
