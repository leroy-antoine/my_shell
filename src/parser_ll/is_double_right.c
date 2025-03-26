/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_double_right
*/

#include <stdbool.h>
#include "tree.h"
#include "my.h"

bool is_double_right(char const *to_check)
{
    if (my_strcmp(to_check, DOUBLE_RIGHT_DELIM) == 0)
        return true;
    return false;
}
