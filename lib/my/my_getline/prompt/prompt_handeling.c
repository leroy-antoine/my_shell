/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** prompt_handeling.c
*/

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"
#include "formatsh.h"

static void reset_prompt(char *prompt)
{
    struct winsize ws = {0};
    char **tab = my_str_to_word_array(prompt, "\n", "");

    if (tab == NULL)
        return;
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) != 0) {
        free_list(tab);
        return;
    }
    del_line(tab[0], ws.ws_col);
    dprintf(STDOUT_FILENO, "%s", str_term_caps[M_CURSOR_UP]);
    del_line(tab[1], ws.ws_col);
    dprintf(STDOUT_FILENO, "%s", prompt);
    free_list(tab);
}

void prompt_handeling(index_t *ind, char *prompt)
{
    if (ind->buf == NULL)
        ind->buf = calloc(0, 1);
    else
        ind->buf[ind->index] = 0;
    if (ind->buf == NULL)
        return;
    reset_prompt(prompt);
    for (int i = 0; ind->buf[i] != '\0'; i++)
        write(STDOUT_FILENO, &ind->buf[i], 1);
    for (int k = 0; k < ind->index - ind->move_index; k++)
        write(STDOUT_FILENO, MOVE_LEFT, 3);
}
