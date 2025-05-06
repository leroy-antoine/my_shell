/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** array
*/

#include <stdlib.h>

int array_len(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    while (array[i] != NULL)
        i++;
    return i;
}

static void fill_array(char **new, char **dst, char **tab, int copy)
{
    int len = array_len(dst) + array_len(tab);
    int first = 0;
    int second = 0;

    for (int i = 0; i < len; i++) {
        if (i == copy) {
            free(dst[first]);
            first++;
        }
        if (i >= copy && tab[second] != NULL) {
            new[i] = tab[second];
            second++;
        } else {
            new[i] = dst[first];
            first++;
        }
    }
}

char **arraycat_n(char **dst, char **tab, int copy)
{
    int len = array_len(dst) + array_len(tab);
    char **new = malloc(sizeof(char *) * len);

    if (new == NULL)
        return NULL;
    fill_array(new, dst, tab, copy);
    free(dst);
    free(tab);
    return new;
}
