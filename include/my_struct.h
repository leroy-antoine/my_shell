/*
** EPITECH PROJECT, 2024
** my_struct.h
** File description:
** struct for this project
*/


#ifndef MY_STRUCT
    #define MY_STRUCT
    #define ERROR 84
    #define SUCCESS 0
    #define SYS_SEG 139
    #define ERROR_LS 2
    #define WRONG 1
    #define ERROR_SHELL 127
    #define SIGNAL_ERR 512
    #define BUFF_SIZE 512
    #define EXIT -2
    #define EMPTY_COMMAND_LINE -678
    #define WRONG_COMMAND 32512
    #define NO_RIGHTS -67
    #define PWD "PWD"
    #define NO_VAL "                "
    #define HOME "HOME"
    #define PATH "PATH"
    #define PATH_VAR "/usr/bin:/bin"
    #include <stddef.h>

typedef struct linked_list_s {
    char *left;
    char *right;
    struct linked_list_s *head;
    struct linked_list_s *next;
} linked_list_t;

char **set_env(char **command, char **env, linked_list_t **my_env);
char **unset_env(char **command, char **env, linked_list_t **my_env);
char **built_in_cd(char **command, char **env, linked_list_t **my_env);
char **print_env(char **command, char **my_env, linked_list_t **env);

typedef struct list_s {
    char *key;
    char **(*func)(char **args, char **env, linked_list_t **);
} list_t;

static const list_t func[] = {
    {"env", &print_env},
    {"cd", &built_in_cd},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"\0", NULL}};

void free_list(linked_list_t **head);
linked_list_t *create_linked_list(linked_list_t **my_env, char **env);
char **create_env_from_list(linked_list_t **my_env);
int
find_command(char **infos, linked_list_t **my_env);
int find_size_list(linked_list_t *head);
char **manage_env(linked_list_t **head);
linked_list_t *delete_elem(linked_list_t *elem, linked_list_t *elem_next);
#endif /* MY_STRUCT */
