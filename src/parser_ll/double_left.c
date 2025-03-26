/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** double_left
*/

#include <stdbool.h>
#include "tree.h"
#include "my.h"

bool is_double_left(char const *to_check)
{
    if (my_strcmp(to_check, DOUBLE_LEFT_DELIM) == 0)
        return true;
    return false;
}
