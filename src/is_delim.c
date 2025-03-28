/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_delim
*/

#include "tree.h"
#include "my_struct.h"

int is_delim(char *str, int i)
{
    if ((i > 0 && str[i - 1] != ' ') ||
        (str[i + 1] != '\0' && str[i + 1] != ' ')) {
        if (str[i] == DELIMS[3] || str[i] == DELIMS[0])
            return BASIC_OPERATOR;
        if ((str[i] == DELIMS[1] &&
            str[i + 1] != '\0' && str[i + 1] == DELIMS[1]) ||
            (str[i] == DELIMS[2] &&
            str[i + 1] != '\0' && str[i + 1] == DELIMS[2])) {
            return EDGE_OPERATOR;
            }
        if (str[i] == DELIMS[1] || str[i] == DELIMS[2])
            return BASIC_OPERATOR;
        }
    return SUCCESS;
}
