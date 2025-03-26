/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** splits a string into an array
*/

#include <stdbool.h>
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

static int len_stay(const char *buff, char c)
{
    int i = 0;

    while (buff[i] != '\0' && buff[i] != c)
        i++;
    if (buff[i] == c)
        i++;
    return i;
}

static int count_words(char const *buff, char const *delim,
    const char *stay)
{
    int nb_words = 0;

    if (buff == NULL || delim == NULL)
        return -1;
    while (*buff != '\0') {
        if (is_it_delim(*buff, delim)) {
            buff++;
            continue;
        }
        if (is_it_delim(*buff, stay)) {
            buff += len_stay(&buff[1], *buff) + 1;
            nb_words++;
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

static char *duplicate_stay(char const *buff, char c)
{
    char *str = malloc(len_stay(buff, c) + 1);
    int i = 0;

    if (str == NULL)
        return NULL;
    while (buff[i] != '\0' && buff[i] != c) {
        str[i] = buff[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

static char **fill_array(char const *buff, char const *delim,
    const char *stay, char **array)
{
    int index = 0;
    int len = 0;

    while (*buff != '\0') {
        if (is_it_delim(*buff, delim)) {
            buff++;
            continue;
        }
        if (is_it_delim(*buff, stay) == true) {
            array[index] = duplicate_stay(&buff[1], *buff);
            buff += len_stay(&buff[1], *buff) + 1;
            index++;
            continue;
        }
        len = size_word(buff, delim);
        array[index] = fill_index(buff, delim, len);
        buff += len;
        index += 1;
    }
    return array;
}

char **my_str_to_word_array(char const *buff, char const *delim,
    const char *stay)
{
    int nb_words = count_words(buff, delim, stay);
    char **array = NULL;

    if (nb_words == - 1 || buff == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (array == NULL)
        return NULL;
    array[nb_words] = NULL;
    return fill_array(buff, delim, stay, array);
}
