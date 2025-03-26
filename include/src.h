/*
** EPITECH PROJECT, 2024
** zzz
** File description:
** zzz
*/

#ifndef SRC_H
    #define SRC_H
    #include <stdbool.h>

int return_val(int signal);
char **parse_commands(char *command);
int exec_cat(char **command, char **env);
int execute_command(char **command, char **env);
char *parse_env_find_command(char **env, char *command);
void free_env(char **env);
int my_shell(char **env);
int size_command(char **command);
#endif /* SRC_H */
