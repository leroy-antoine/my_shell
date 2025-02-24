/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** rompich
*/

#include <stddef.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i = i + 1;
    return i;
}
