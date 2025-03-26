/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** binary_tree
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my.h"
#include "tree.h"

static int find_index(tree_t *tree, const int i, int *type)
{
    int index = INIT_INDEX;

    for (int j = 0; func_list[j] != NULL; j++) {
        if (func_list[j](tree->infos[i])) {
            index = i;
            (*type) = j;
        }
        if (index != INIT_INDEX)
            return index;
    }
    return index;
}

static void determine_index_delim(tree_t *tree, int *index)
{
    int type = INIT_INDEX;
    int last_type = 0;
    int new_index = 0;

    if (tree == NULL || tree->infos == NULL)
        return;
    for (int i = 0; tree->infos[i] != NULL; i++) {
        last_type = type;
        new_index = find_index(tree, i, &type);
        if (type <= last_type && new_index != INIT_INDEX) {
            *index = new_index;
        }
    }
    if (*index == INIT_INDEX) {
        tree->redirect_type = NONE;
    }
}

static char **split_array(char ***right, char ***left, int index,
    char **infos)
{
    int len = my_list_len(infos);
    int index_right = 0;

    if (index == INIT_INDEX)
        return infos;
    *left = malloc(sizeof(char *) * (index + 1));
    *right = malloc(sizeof(char *) * (len - index));
    if (*left == NULL || *right == NULL)
        return NULL;
    (*left)[index] = NULL;
    (*right)[len - index - 1] = NULL;
    for (int i = 0; infos[i] != NULL; i++) {
        if (i < index)
            (*left)[i] = my_strdup(infos[i]);
        if (i > index) {
            (*right)[index_right] = my_strdup(infos[i]);
            index_right++;
        }
    }
    return infos;
}

static void determine_type(tree_t *tree, int index)
{
    int redirect_type = NONE;

    if (tree->infos == NULL || tree->redirect_type == NONE)
        return;
    for (int j = 0; func_list[j] != NULL; j++) {
        if (func_list[j](tree->infos[index]))
            redirect_type = j;
    }
    tree->redirect_type = redirect_type;
}

static tree_t *init_tree(char **infos)
{
    tree_t *tree = NULL;

    if (infos == NULL)
        return NULL;
    tree = malloc(sizeof(tree_t));
    if (tree == NULL)
        return NULL;
    tree->infos = infos;
    tree->left = NULL;
    tree->redirect_type = INIT_INDEX;
    tree->right = NULL;
    return tree;
}

static tree_t *create_tree(char **infos)
{
    tree_t *tree = init_tree(infos);
    int index_delim = INIT_INDEX;
    char **left_arr = NULL;
    char **right_arr = NULL;

    if (tree == NULL)
        return NULL;
    tree->infos = infos;
    determine_index_delim(tree, &index_delim);
    determine_type(tree, index_delim);
    if (split_array(&right_arr, &left_arr, index_delim,
        tree->infos) == NULL)
        return NULL;
    if (right_arr != NULL && tree->redirect_type != NONE)
        tree->right = create_tree(right_arr);
    if (left_arr != NULL && tree->redirect_type != NONE)
        tree->left = create_tree(left_arr);
    return tree;
}

tree_t *binary_tree(char **infos)
{
    tree_t *tree = create_tree(infos);

    return tree;
}
