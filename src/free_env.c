/*
** EPITECH PROJECT, 2025
** free_env.c
** File description:
** free the env
*/

#include <stdlib.h>

void free_env(char **env)
{
    if (env == NULL)
        return;
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
}
