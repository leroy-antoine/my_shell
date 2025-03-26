/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_semicolon
*/

#include <stdbool.h>
#include "tree.h"
#include "my.h"

bool is_semicolon(char const *to_check)
{
    if (my_strcmp(to_check, SEMICOLON_DELIM) == 0)
        return true;
    return false;
}
