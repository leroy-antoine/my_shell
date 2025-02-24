/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** zzz
*/

#include <stddef.h>
#include "my.h"

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 84;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
        i++;
    }
    if (s1[i] < s2[i])
        return -1;
    if (s1[i] > s2[i])
        return 1;
    return 0;
}
