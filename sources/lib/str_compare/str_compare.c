/*
** EPITECH PROJECT, 2021
** str_compare.
** File description:
** This program compare 2 string and return 0 if he's the same string.
*/

#include "../../../includes/lib.h"

int str_compare(char *str1, char *str2)
{
    int same_letter = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == str2[i])
            same_letter++;
    }
    if (my_strlen(str1) == same_letter)
        return (1);
    return (0);
}

int str_compare_nolen(char *str1, char *str2)
{
    int same_letter = 0;

    for (int i = 0; my_strchr(str1, str2[i]) == 0; i++) {
        same_letter++;
    }
    if (my_strlen(str1) == same_letter)
        return (1);
    return (0);
}
