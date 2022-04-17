/*
** EPITECH PROJECT, 2021
** memory.
** File description:
** Memory function file.
*/

#include <stdlib.h>
#include "../../includes/lib.h"

int my_strstr_len(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

void tab_char_free(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}

void print_tab_char(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        my_putstr("\n");
    }
}

void verif_malloc(char **str)
{
    if (str == NULL)
        exit(84);
}
