/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_env
*/

#include "mysh.h"

void free_env_var(void *data)
{
    env_var_t *env_var = (env_var_t *)data;

    free(env_var->line);
    free(env_var);
}
