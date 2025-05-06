/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** is_env_var.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"
#include "my.h"
#include "formatsh.h"

bool is_env_variable(linked_list_t *env, const char *var)
{
    node_t *node = NULL;
    char *buff = NULL;
    char *line = NULL;

    if (env == NULL || var == NULL)
        return false;
    node = env->head;
    while (node != NULL) {
        line = strdup(((env_var_t *)node->data)->line);
        buff = strtok_r(line, str_message[EQUAL], &line);
        if (strcmp(buff, var) == 0) {
            free(buff);
            return true;
        }
        node = node->next;
    }
    return false;
}
