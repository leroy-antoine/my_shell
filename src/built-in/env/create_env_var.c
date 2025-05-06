/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** create_env_var
*/

#include <string.h>
#include "mysh.h"
#include "my.h"

env_var_t *create_env_var(char *str)
{
    env_var_t *env_var = malloc(sizeof(env_var_t));

    if (env_var == NULL)
        return NULL;
    env_var->line = strdup(str);
    if (env_var->line == NULL)
        return NULL;
    return env_var;
}
