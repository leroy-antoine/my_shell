/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** return_val
*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"

int return_val(int signal)
{
    int status = WTERMSIG(signal);

    if (status == 0)
        return WEXITSTATUS(signal);
    if (status == SIGFPE)
        my_putstrd("Floating exception");
    else
        my_putstrd(strsignal(status));
    if (WCOREDUMP(status) == 0)
        my_putstrd(" (core dumped)");
    my_putstrd("\n");
    return signal;
}
