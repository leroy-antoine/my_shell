/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** splits a string into an array
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int is_it_delim(char const to_check, char const *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
        if (to_check == delim[i])
            return true;
    return false;
}

static int size_word(char const *buff, char const *delim)
{
    int index = 0;

    while (buff[index] != '\0' && !is_it_delim(buff[index], delim))
        index += 1;
    return index;
}

static int count_words(char const *buff, char const *delim)
{
    int nb_words = 0;

    if (buff == NULL || delim == NULL)
        return -1;
    while (*buff != '\0') {
        if (is_it_delim(*buff, delim)) {
            buff++;
            continue;
        }
        buff += size_word(buff, delim);
        nb_words += 1;
    }
    return nb_words;
}

static char *fill_index(char const *buff, char const *delim, int len)
{
    char *index = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (index == NULL)
        return NULL;
    while (buff[i] != '\0' && !is_it_delim(buff[i], delim)) {
        index[i] = buff[i];
        i += 1;
    }
    index[len] = '\0';
    return index;
}

static char **fill_array(char const *buff, char const *delim, char **array)
{
    int index = 0;
    int len = 0;

    while (*buff != '\0') {
        if (is_it_delim(*buff, delim)) {
            buff++;
            continue;
        }
        len = size_word(buff, delim);
        array[index] = fill_index(buff, delim, len);
        buff += len;
        index += 1;
    }
    array[index] = NULL;
    return array;
}

char **my_str_to_word_array(char const *buff, char const *delim)
{
    int nb_words = count_words(buff, delim);
    char **array = NULL;

    if (nb_words == - 1)
        return NULL;
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (array == NULL)
        return NULL;
    array[nb_words] = NULL;
    return fill_array(buff, delim, array);
}
