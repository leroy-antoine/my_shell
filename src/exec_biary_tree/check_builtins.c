/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** check_builtins
*/

#include <stdlib.h>

#include "tree.h"
#include "src.h"
#include "my.h"
#include "my_struct.h"

static int check_builtins(linked_list_t **my_env, char **infos, char **env)
{
    char **return_val = NULL;
    bool is_builtin = false;

    if (env == NULL)
        return ERROR;
    for (int i = 0; func[i].key[0] != '\0'; i++)
        if (my_strcmp(infos[0], func[i].key) == 0) {
            return_val = func[i].func(infos, env, my_env);
            is_builtin = true;
            break;
        }
    if (is_builtin && return_val != NULL)
        return SUCCESS;
    if (is_builtin && return_val == NULL)
        return ERROR;
    return ISNT_BUILTIN;
}

int find_which_exec(linked_list_t **my_env, char **infos, char **env)
{
    int builtin_val = check_builtins(my_env, infos, env);

    if (env == NULL)
        return ERROR;
    if (builtin_val == ISNT_BUILTIN)
        execute_command(infos, env);
    free_env(env);
    return builtin_val;
}
