/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** is_esc.c
*/

#include <stdbool.h>
#include "mysh.h"

bool is_esc(char c)
{
    return c == ESC;
}
