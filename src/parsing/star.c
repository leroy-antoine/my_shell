/*
** EPITECH PROJECT, 2025
** star
** File description:
** star.c
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glob.h>
#include "my.h"
#include "mysh.h"
#include "formatsh.h"

void del_index(char **list, int index)
{
    int i = 0;

    while (i != index)
        ++i;
    free(list[i]);
    while (list[i] != NULL) {
        list[i] = list[i + 1];
        ++i;
    }
}

static int copy_founds(char **argv, char **found, size_t nb_found)
{
    free(argv[EPI_SUCCESS]);
    for (size_t i = EPI_SUCCESS; found[i] != NULL && i < nb_found; ++i) {
        argv[i] = strdup(found[i]);
        if (argv[i] == NULL)
            return EPI_ERROR;
    }
    return EPI_SUCCESS;
}

static char **insert(char **argv, size_t index, char **found, size_t nb_found)
{
    char **final = NULL;
    size_t len = my_list_len(argv);
    size_t j = EPI_SUCCESS;

    if (index > len || argv == NULL || found == NULL)
        return NULL;
    final = calloc(len + nb_found + 1, sizeof(char *));
    if (final == NULL)
        return NULL;
    for (size_t i = EPI_SUCCESS; i < len + nb_found; ++i) {
        if (i == index) {
            copy_founds(&final[index], found, nb_found);
            i += nb_found - 1;
        } else
            final[i] = argv[j];
        ++j;
    }
    free(argv);
    return final;
}

static void get_files(char ***argv, size_t *i, bool *is_found)
{
    glob_t globing = {EPI_SUCCESS};

    if (glob((*argv)[*i], GLOB_ERR, NULL, &globing) != EPI_SUCCESS) {
        del_index(*argv, *i);
        --(*i);
        return;
    }
    *is_found = true;
    *argv = insert(*argv, *i, globing.gl_pathv, globing.gl_pathc);
    globfree(&globing);
}

static int is_star(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '*')
            return 1;
    return EPI_SUCCESS;
}

static int is_change_star(char **argv)
{
    for (int i = 0; argv[i] != NULL; ++i)
        if (is_star(argv[i]) == 1)
            return 1;
    return EPI_SUCCESS;
}

int handle_star(char ***argv)
{
    bool is_match = false;

    if (*argv == NULL)
        return EPI_ERROR;
    if (is_change_star(*argv) == EPI_SUCCESS)
        return EPI_SUCCESS;
    for (size_t i = 0; (*argv)[i] != NULL; ++i) {
        if (is_star((*argv)[i]) == 1)
            get_files(argv, &i, &is_match);
        if (*argv == NULL) {
            is_match = false;
            break;
        }
    }
    if (is_match == false || *argv == NULL) {
        dprintf(2, str_message[NO_MATCH_STAR],
            (*argv) == NULL ? "" : (*argv)[0]);
        return EPI_ERROR;
    }
    return EPI_SUCCESS;
}
