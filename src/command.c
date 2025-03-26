/*
** EPITECH PROJECT, 2025
** command.c
** File description:
** handle commands
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my.h"
#include "src.h"

void is_there_path(linked_list_t **my_env)
{
    linked_list_t *tmp = (*my_env);

    if (tmp == NULL)
        return;
    while (tmp->next != NULL) {
        if (my_strcmp(tmp->left, "PATH") == 0)
            return;
        tmp = tmp->next;
    }
    if (my_strcmp(tmp->left, "PATH") == 0)
        return;
    tmp->next = malloc(sizeof(linked_list_t));
    if (tmp->next == NULL)
        return;
    tmp->next->left = my_strdup(PATH);
    tmp->next->right = my_strdup(PATH_VAR);
    tmp->next->next = NULL;
}

static int print_error(char *command, char **env)
{
    my_putstrd(command);
    my_putstrd(": Command not found.\n");
    free_env(env);
    return WRONG;
}

static int find_return_val(int signal, char *command, char **env)
{
    if (signal == WRONG_COMMAND || signal == WRONG_COMMAND_SIGNAL)
        return print_error(command, env);
    return return_val(signal);
}

static int exec_command(char **command, char **env)
{
    pid_t id = 0;
    int signal = 0;

    id = fork();
    if (id == 0)
        exit(execute_command(command, env));
    if (id > 0) {
        waitpid(id, &signal, 0);
        return find_return_val(signal, command[0], env);
    }
    if (id == -1)
        mini_printf("unknown failure\n");
    return ERROR;
}

int find_command(char **infos, linked_list_t **my_env)
{
    int command_return = 0;
    int is_in_list = ISNT_IN_LIST;
    char **env = NULL;

    is_there_path(my_env);
    env = create_env_from_list(my_env);
    for (int i = 0; func[i].key[0] != '\0'; i++)
        if (my_strcmp(infos[0], func[i].key) == 0) {
            is_in_list = i;
            break;
        }
    if (is_in_list != ISNT_IN_LIST)
        if (func[is_in_list].func(infos, env, my_env) == NULL)
            return ERROR;
    if (is_in_list == ISNT_IN_LIST)
        command_return = exec_command(infos, env);
    if (env == NULL)
        return ERROR;
    return command_return;
}
