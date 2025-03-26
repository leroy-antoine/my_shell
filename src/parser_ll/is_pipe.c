/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** is_pipe
*/

#include <stdbool.h>
#include "tree.h"
#include "my.h"

bool is_pipe(char const *to_check)
{
    if (my_strcmp(to_check, PIPE_DELIM) == 0) {
        return true;
    }
    return false;
}
