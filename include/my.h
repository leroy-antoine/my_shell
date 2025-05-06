/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define HELP "src/help.txt"

    #define EPI_SUCCESS 0
    #define EPI_ERROR 84

char **copy_arr(char **arr);
    #include <stdio.h>

typedef enum {
    MY_NAN,
    NATURAL,
    INTEGER,
    RATIONAL,
} nb_group_t;

int is_int_float(char *av);
char **my_str_to_word_array(char const *buffer,
    char const *delim, char const *stay);
int my_intlen(int nb);
int my_is_number(char *str);
void free_list(char **list);
int my_list_len(char **list);
char **dup_list(char **list);
char *my_strcat_inf(int count, char *str, ...);
char *my_strdup_delim(char const *path, char c);
void my_dputstr(char const fd, char const *str);
int my_free(int return_value, int fd, const char *error_message, ...);
int is_file(char *path);
char *open_file(const char *file);
int help(void);
char **dup_list_ij(char **list, int i, int j);
int array_len(char **array);
char **arraycat_n(char **dst, char **tab, int copy);
long int get_file_lines_nb(FILE *stream);
void get_to_nth_line(FILE *stream, int n);
char *my_join_array(char **array, char *separator);
void my_show_word_array(char **arr);
char **my_merge_word_array(char **arr_1, char **arr_2);
void my_free_str(char **str);
char *my_revstrndup(char *str, int n);

#endif
