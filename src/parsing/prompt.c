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


int prompt(prompt_t *variables, system_t *sys)
{
    if (sys->prompt != NULL)
        free(sys->prompt);
    feat_prompt_tab[0].add_feat(variables, sys);
    feat_prompt_tab[1].add_feat(variables, sys);
    feat_prompt_tab[2].add_feat(variables, sys);
    feat_prompt_tab[3].add_feat(variables, sys);
    feat_prompt_tab[4].add_feat(variables, sys);
    feat_prompt_tab[5].add_feat(variables, sys);
    return SUCCESS;
}
