/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** get_input.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "my.h"
#include "mysh.h"
#include "formatsh.h"


static int format_tab_cmd(char ***args, prompt_t *variables, system_t *sys)
{
    check_alias(args, sys->alias);
    if (*args == NULL)
        return EPI_ERROR;
    if (replace_wave(*args, sys->env) == COMMAND_ERROR ||
        handle_star(args) == EPI_ERROR) {
        variables->status = COMMAND_ERROR;
        return COMMAND_ERROR;
    }
    return EPI_SUCCESS;
}

int check_tty(char **command, int *stop_getline, system_t *sys, prompt_t *vars)
{
    size_t size = 0;

    if (isatty(STANDARD_INPUT) == 0) {
        if (getline(command, &size, stdin) == EOF) {
            *stop_getline = EOF;
        }
    } else {
        if (prompt(vars, get_env_var(
            sys->env, str_env[HOME_VAR]), sys) == ERROR)
            return ERROR;
        *stop_getline = my_getline(sys->prompt, command, &size, STDIN_FILENO);
    }
    return SUCCESS;
}

int get_input(char **command,
    char ***args, prompt_t *variables, system_t *sys)
{
    char *tmp = NULL;
    int stop_getline = 0;

    check_tty(command, &stop_getline, sys, variables);
    add_to_history(*command, sys->history);
    tmp = format_cmd(*command);
    if (tmp == NULL)
        return EPI_ERROR;
    if (*command == NULL)
        return EPI_ERROR;
    *args = my_str_to_word_array(tmp, " \n\t", "\"\'");
    if (*args == NULL)
        return COMMAND_ERROR;
    free(tmp);
    free(*command);
    if (stop_getline == EOF)
        return EPI_ERROR;
    return format_tab_cmd(args, variables, sys);
}
