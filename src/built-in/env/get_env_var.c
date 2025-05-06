/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** get_env_var.c
*/

#include <string.h>
#include <stdlib.h>
#include "mysh.h"
#include "formatsh.h"
#include "my.h"

char *get_env_var(linked_list_t *env, const char *var)
{
    char *buff = NULL;
    node_t *node = NULL;
    char *line = NULL;

    if (env == NULL || var == NULL)
        return NULL;
    node = env->head;
    while (node != NULL) {
        line = strdup(((env_var_t *)node->data)->line);
        buff = strtok_r(line, str_management[EQUAL], &line);
        if (strcmp(buff, var) == 0) {
            buff = strtok_r(NULL, "", &line);
            return (buff == NULL ? NULL : strdup(buff));
        }
        node = node->next;
    }
    return NULL;
}
