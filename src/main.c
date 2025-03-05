/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my_struct.h"
#include "../include/my.h"

int main(int, char **, char **env)
{
    if (env == NULL)
        return ERROR;
    return my_shell(env);
}
