/*
** EPITECH PROJECT, 2021
** Parser Program.
** File description:
** This program parse string in different word.
*/

#include <stdlib.h>
#include "../../../includes/lib.h"
#include <stdio.h>
#include <stdbool.h>

char **str_to_word_tab(char *str, char *pars_characters)
{
    char **tab = init_table(str, pars_characters);
    int k = 0;

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i < number_of_word(str, pars_characters); i++) {
        while (my_strchr(pars_characters, str[k]) == 0)
        k++;
        for (int y = 0; is_valid(str[k], pars_characters) == true; y++) {
            tab[i][y] = str[k];
            k++;
        }
    }
    return (tab);
}

char **init_table(char *str, char *pars_characters)
{
    int word_number = number_of_word(str, pars_characters);
    char **tab = malloc(sizeof(char *) * (word_number + 1));

    if (tab == NULL)
        return (NULL);
    tab = init_table_box(str, pars_characters, word_number, tab);
    return (tab);
}

char **init_table_box(char *str, char *pars_characters, int word, char **tab)
{
    int pos = 0;
    int word_size = 0;

    for (int i = 0; i < word; i++) {
        while (is_valid(str[pos], pars_characters) == false)
        pos++;
        while (is_valid(str[pos], pars_characters) == true) {
            pos++;
            word_size++;
        }
        tab[i] = malloc(sizeof(char) * (word_size + 1));
        tab[i][word_size] =  '\0';
        if (tab[i] == NULL)
            return (NULL);
        word_size = 0;
        if (str[pos] != '\0')
            pos++;
    }
    tab[word] = NULL;
    return (tab);
}

bool is_valid(char c, char *pars_characters)
{
    if (c == '\0')
        return (false);
    else if (my_strchr(pars_characters, c) == 0)
        return (false);
    else
        return (true);
}

int number_of_word(char *str, char *pars_characters)
{
    int number_of_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strchr(pars_characters, str[i + 1]) == 0
            && my_strchr(pars_characters, str[i]) == 1)
            number_of_word += 1;
        else if (str[i + 1] == '\0' &&
                is_valid(str[i], pars_characters) == true)
            number_of_word += 1;
    }
    return (number_of_word);
}
