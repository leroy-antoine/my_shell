/*
** EPITECH PROJECT, 2025
** size_command.c
** File description:
** size_command
*/

#include <stddef.h>

int size_command(char **command)
{
    int size = 0;

    while (command[size] != NULL)
        size += 1;
    return size;
}
