/*
** EPITECH PROJECT, 2025
** parse_array.c
** File description:
** parse array
*/

#include <stdlib.h>
#include "my.h"
#include "my_struct.h"
#include "tree.h"

static void fill_char_delim(char *last, char *new_str, int *index_new, int i)
{
    new_str[*index_new] = ' ';
    new_str[*index_new + 1] = last[i];
    new_str[*index_new + 2] = ' ';
    *index_new += 2;
}

static void fill_char_edgecase(char *last, char *new_str,
    int *index_new, int *i)
{
    new_str[*index_new] = ' ';
    new_str[*index_new + 1] = last[*i];
    new_str[*index_new + 2] = last[*i + 1];
    new_str[*index_new + 3] = ' ';
    *index_new += 3;
    *i += 1;
}

static char *create_new_str(char *last, char *new_str)
{
    int index_new = 0;
    int delim = 0;

    for (int i = 0; last[i] != '\0'; i++) {
        delim = is_delim(last, i);
        if (delim == BASIC_OPERATOR) {
            fill_char_delim(last, new_str, &index_new, i);
        }
        if (delim == EDGE_OPERATOR) {
            fill_char_edgecase(last, new_str, &index_new, &i);
        }
        if (delim == 0)
            new_str[index_new] = last[i];
        index_new += 1;
    }
    return new_str;
}

char *parse_array(char *str)
{
    int len = my_strlen(str);
    int nb_spaces = 0;
    char *new_str = NULL;
    int delim = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        delim = is_delim(str, i);
        if (delim == BASIC_OPERATOR)
            nb_spaces += 2;
        if (delim == EDGE_OPERATOR) {
            nb_spaces += 2;
            i++;
        }
    }
    new_str = malloc(sizeof(char) * (len + nb_spaces + 1));
    if (new_str == NULL)
        return NULL;
    new_str[len + nb_spaces] = '\0';
    return create_new_str(str, new_str);
}
