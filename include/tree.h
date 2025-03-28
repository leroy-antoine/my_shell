/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** tree
*/

#ifndef TREE_H
    #define TREE_H
    #include <stddef.h>
    #include <stdbool.h>
    #define DELIMS ";<>|\0"
    #define DOUBLE_LEFT_INDEX 1
    #define DOUBLE_RIGHT_INDEX 2
    #define INIT_INDEX 900
    #define NB_FUNC 7
    #define BASIC_OPERATOR 1
    #define EDGE_OPERATOR 2
    #define DOUBLE_LEFT_DELIM "<<\0"
    #define DOUBLE_RIGHT_DELIM ">>\0"
    #define LEFT_DELIM "<\0"
    #define RIGHT_DELIM ">\0"
    #define SEMICOLON_DELIM ";\0"
    #define PIPE_DELIM "|\0"
    #define ISNT_BUILTIN -1

typedef struct linked_list_s linked_list_t;

enum delim {
    SEMILCOLON,
    REDIRECT_LEFT,
    LEFT_LEFT,
    REDIRECT_RIGHT,
    RIGHT_RIGHT,
    PIPE,
    NONE
};

bool is_semicolon(char const *to_check);
bool is_left(char const *to_check);
bool is_double_left(char const *to_check);
bool is_right(char const *to_check);
bool is_double_right(char const *to_check);
bool is_pipe(char const *to_check);

static bool (* const func_list[NB_FUNC])(char const *) = {
    is_semicolon,
    is_left,
    is_double_left,
    is_right,
    is_double_right,
    is_pipe,
    NULL
};

typedef struct tree_s {
    char **infos;
    int redirect_type;
    struct tree_s *right;
    struct tree_s *left;
} tree_t;

typedef struct operators_s {
    int ID;
    int (*operators)(tree_t *, linked_list_t **);
} operators_t;

int semicolon_exec(tree_t *tree, linked_list_t **my_env);
int left_exec(tree_t *tree, linked_list_t **my_env);
int double_left_exec(tree_t *tree, linked_list_t **my_env);
int right_exec(tree_t *tree, linked_list_t **my_env);
int double_right_exec(tree_t *tree, linked_list_t **my_env);
int pipe_exec(tree_t *tree, linked_list_t **my_env);

static const operators_t operators[] = {
    {0, &semicolon_exec},
    {1, &left_exec},
    {2, &double_left_exec},
    {3, &right_exec},
    {4, &double_right_exec},
    {5, &pipe_exec},
    {6, NULL}};

tree_t *binary_tree(char **infos);
int conditional_exec(char **infos, linked_list_t **my_env);
int exec_binary_tree(tree_t *tree, linked_list_t **my_env);
bool find_the_delim(char *to_check);
char **copy_arr(char **arr, int index, bool ncpy, int nend);
int find_which_exec(linked_list_t **my_env, char **infos, char **env);
char *parse_array(char *str);
int is_delim(char *str, int i);
int right_redirection(tree_t *tree, linked_list_t **my_env,
    int index, int fd);
bool handle_errors_redirections(tree_t *tree);
void free_redirections(char **env, char **arr,
    int fd);
#endif /* TREE_H */
