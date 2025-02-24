/*
** EPITECH PROJECT, 2025
** my_putstr_d
** File description:
** put_str_d
*/

#include <unistd.h>
#include "my.h"

int my_putstrd(char const *str)
{
    unsigned long len = 0;

    if (str == NULL)
        return 84;
    len = my_strlen(str);
    write(2, str, len);
    return 0;
}
