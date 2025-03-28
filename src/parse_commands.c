/*
** EPITECH PROJECT, 2025
** parse_commands.c
** File description:
** parse commands
*/

#include <stdlib.h>
#include "my.h"
#include "src.h"
#include "tree.h"

static char *modify_if_operators(char *command)
{
    int is_operator = 0;
    int operators_count = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        is_operator = is_delim(command, i);
        if (is_operator == EDGE_OPERATOR ||
            is_operator == BASIC_OPERATOR)
            operators_count++;
    }
    if (operators_count == 0)
        return command;
    return parse_array(command);
}

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
    command = modify_if_operators(command);
    infos = my_str_to_word_array(command, " \t\n", "\"");
    if (infos == NULL)
        return NULL;
    return infos;
}
