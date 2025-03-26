/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** copy_arr
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char **ncpy_arr(char **arr, int nend, char **copy, int index)
{
    int start = 0;
    int len = my_list_len(arr) - index;

    if (len == 0)
        return NULL;
    copy = malloc(sizeof(char *) * (len + 1));
    if (copy == NULL)
        return NULL;
    for (int i = index + 1; arr[i] != NULL && i <= nend
        && arr[i][0] != '|'; i++) {
        copy[start] = my_strdup(arr[i]);
        if (copy[start] == NULL)
            return NULL;
        start++;
    }
    copy[start] = NULL;
    return copy;
}

char **copy_arr(char **arr, int index, bool ncpy, int nend)
{
    char **copy = NULL;

    if (arr == NULL || index < 0)
        return NULL;
    if (ncpy)
        return ncpy_arr(arr, nend, copy, index);
    copy = malloc(sizeof(char *) * (index + 1));
    if (copy == NULL) {
        my_putstrd("ERROR : malloc failed");
        return NULL;
    }
    for (int i = 0; arr[i] != NULL && i <= index; i++) {
        copy[i] = my_strdup(arr[i]);
        if (copy[i] == NULL) {
            my_putstrd("ERROR : malloc failed");
            return NULL;
        }
    }
    copy[index] = NULL;
    return copy;
}
