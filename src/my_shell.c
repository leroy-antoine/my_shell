/*
** EPITECH PROJECT, 2025
** my_shell.c
** File description:
** my_shell.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_struct.h"
#include "../include/my.h"
#include "../include/src.h"

static void check_tty(void)
{
    int fd = STDIN_FILENO;

    if (isatty(fd) == 1)
        my_putstr("\x1b[35m < O_O > \x1b[0m");
}

static void free_everything(char **command)
{
    if (command == NULL)
        return;
    for (int i = 0; command[i] != NULL; i++)
        free(command[i]);
    free(command);
}

static int get_input(char *command, size_t line,
    char **infos, linked_list_t **env)
{
    int return_val = 0;

    while (getline(&command, &line, stdin) != -1) {
        if (command[0] == '\n') {
            check_tty();
            continue;
        }
        if (command[0] == '\n')
            continue;
        infos = parse_commands(command);
        if (infos == NULL)
            return ERROR;
        if (my_strcmp(infos[0], "exit") == 0)
            break;
        return_val = find_command(infos, env);
        check_tty();
        free_everything(infos);
    }
    free(command);
    return return_val;
}

int my_shell(char **env)
{
    char *command = NULL;
    char **infos = NULL;
    int return_val = 0;
    size_t line = 0;
    linked_list_t *my_env = create_linked_list(&my_env, env);

    check_tty();
    return_val = get_input(command, line, infos, &my_env);
    if (isatty(STDIN_FILENO))
        mini_printf("exit\n");
    free_list(&my_env);
    return return_val;
}
