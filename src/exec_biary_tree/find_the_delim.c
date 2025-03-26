/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_it_delim
*/

#include "my.h"
#include "tree.h"

bool find_the_delim(char *to_check)
{
    if (my_strcmp(to_check, DOUBLE_LEFT_DELIM) == 0 ||
        my_strcmp(to_check, DOUBLE_RIGHT_DELIM) == 0 ||
        my_strcmp(to_check, LEFT_DELIM) == 0 ||
        my_strcmp(to_check, RIGHT_DELIM) == 0 ||
        my_strcmp(to_check, SEMICOLON_DELIM) == 0 ||
        my_strcmp(to_check, PIPE_DELIM) == 0)
        return true;
    return false;
}
