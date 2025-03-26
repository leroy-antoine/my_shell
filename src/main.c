/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "src.h"
#include "my_struct.h"

int main(int, char **, char **env)
{
    if (env == NULL)
        return ERROR;
    return my_shell(env);
}
