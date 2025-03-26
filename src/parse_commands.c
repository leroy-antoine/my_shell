/*
** EPITECH PROJECT, 2025
** parse_commands.c
** File description:
** parse commands
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "src.h"

static char *refactor_array(char *command)
{
    int len = my_strlen(command);

    if (command[len - 1] == '\n')
        command[len - 1] = '\0';
    return command;
}

char **parse_commands(char *command)
{
    char **infos = NULL;

    command = refactor_array(command);
    infos = my_str_to_word_array(command, " \t\n", "\"");
    if (infos == NULL)
        return NULL;
    return infos;
}
