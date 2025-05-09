/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** initialize_system
*/

#include <stdio.h>
#include "mysh.h"
#include "my.h"


system_t *initialize_system(char **env)
{
    system_t *system = malloc(sizeof(system_t));
    linked_list_t *my_env = get_env(env);
    linked_list_t *alias = get_alias(my_env);
    history_t *history = get_history(my_env);
    linked_list_t *jobs = init_jobs();
    linked_list_t *var = initialize_linked_list();

    if (system == NULL || my_env == NULL || alias == NULL || jobs == NULL
        || history == NULL || var == NULL)
        return NULL;
    system->env = my_env;
    system->alias = alias;
    system->jobs = jobs;
    system->history = history;
    system->has_exited = false;
    system->prompt = NULL;
    system->var = var;
    return system;
}
