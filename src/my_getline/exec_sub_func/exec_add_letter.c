/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** exec_add_letter.c
*/

#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "formatsh.h"
#include "mysh.h"

int add_letter_eol(index_t *ind, char const c)
{
    ind->move_index++;
    ind->buf = realloc(ind->buf, ind->move_index + 2);
    if (ind->buf == NULL)
        return EPI_ERROR;
    ind->buf[ind->index] = c;
    ind->index++;
    ind->buf[ind->index] = '\0';
    return SUCCESS;
}

int add_letter_mol(index_t *ind, char const c)
{
    char *tmp_start = strndup(ind->buf, ind->move_index);
    char *tmp_end = my_revstrndup(ind->buf, ind->index - ind->move_index);
    char *tmp = malloc(sizeof(char) *
        (strlen(tmp_start) + strlen(tmp_end) + 2));

    ind->buf = realloc(ind->buf, strlen(ind->buf) + 3);
    if (ind->buf == NULL || tmp == NULL ||
        tmp_start == NULL || tmp_end == NULL)
        return EPI_ERROR;
    strcpy(tmp, tmp_start);
    strncat(tmp, &c, 1);
    strcat(tmp, tmp_end);
    strcpy(ind->buf, tmp);
    ind->buf[ind->index + 1] = '\0';
    ind->index++;
    ind->move_index++;
    my_free_str(&tmp);
    my_free_str(&tmp_start);
    my_free_str(&tmp_end);
    return SUCCESS;
}

void exec_add_letter(index_t *ind, char const c)
{
    if (ind->index == ind->move_index) {
        if (add_letter_eol(ind, c) == EPI_ERROR)
            return;
    } else {
        if (add_letter_mol(ind, c) == EPI_ERROR)
            return;
    }
    return;
}
