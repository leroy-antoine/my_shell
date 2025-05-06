/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** prompt.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "mysh.h"
#include "formatsh.h"

static int write_path(char *home, system_t *sys)
{
    char *wd = getcwd(NULL, PATH_MAX_LEN);
    int len = 0;

    if (home != NULL) {
        len = strlen(home);
        if (strncmp(home, wd, len) == 0)
            wd += len;
        else
            len = 0;
        free(home);
    }
    sys->prompt = malloc(sizeof(char) * (dprintf(STDOUT_FILENO,
        "%s~%s>", str_term_caps[MAGENTA], wd) + 1));
    if (sys->prompt == NULL)
        return ERROR;
    sprintf(sys->prompt, "%s~%s>", str_term_caps[MAGENTA], wd);
    if (len != 0)
        wd -= len;
    free(wd);
    return SUCCESS;
}

static int write_hostname(prompt_t *variables, system_t *sys)
{
    int print = 0;

    if (variables->hostname == NULL)
        return SUCCESS;
    print = dprintf(STDOUT_FILENO, "%s ✭ %s%s", str_term_caps[BLUE],
            str_term_caps[YELLOW], variables->hostname);
    sys->prompt = realloc(sys->prompt,
        sizeof(char) * (print + strlen(sys->prompt) + 1));
    if (sys->prompt == NULL)
        return ERROR;
    sprintf(sys->prompt, "%s%s ✭ %s%s", sys->prompt, str_term_caps[BLUE],
            str_term_caps[YELLOW], variables->hostname);
    return SUCCESS;
}

static int write_nb(prompt_t *variables, system_t *sys)
{
    int print = 0;

    if (variables->status == 0)
        print = dprintf(STDOUT_FILENO, "%s\n%d",
            str_term_caps[GREEN], variables->status);
    else
        print = dprintf(STDOUT_FILENO, "%s\n%d",
            str_term_caps[RED], variables->status);
    sys->prompt = realloc(sys->prompt,
        sizeof(char) * (print + strlen(sys->prompt) + 1));
    if (sys->prompt == NULL)
        return ERROR;
    if (variables->status == 0)
        sprintf(sys->prompt, "%s%s\n%d",
            sys->prompt, str_term_caps[GREEN], variables->status);
    else
        sprintf(sys->prompt, "%s%s\n%d",
            sys->prompt, str_term_caps[RED], variables->status);
    return SUCCESS;
}

static int write_user(prompt_t *variables, system_t *sys)
{
    int print = 0;

    if (variables->user == NULL) {
        variables->user = strdup("$ ");
        if (variables->user == NULL)
            return ERROR;
    }
    print = dprintf(STDOUT_FILENO, "%s - %s%s➤ %s",
        str_term_caps[RESET], str_term_caps[CYAN],
        variables->user, str_term_caps[RESET]);
    sys->prompt = realloc(sys->prompt,
        sizeof(char) * (print + strlen(sys->prompt) + 1));
    if (sys->prompt == NULL)
        return ERROR;
    sprintf(sys->prompt, "%s%s - %s%s➤ %s",
        sys->prompt, str_term_caps[RESET], str_term_caps[CYAN],
        variables->user, str_term_caps[RESET]);
    return SUCCESS;
}

int prompt(prompt_t *variables, char *home, system_t *sys)
{
    if (sys->prompt != NULL) {
        free(sys->prompt);
    }
    if (write_path(home, sys) == ERROR
        || write_hostname(variables, sys) == ERROR
        || write_nb(variables, sys) == ERROR
        || write_user(variables, sys) == ERROR)
        return ERROR;
    return SUCCESS;
}
