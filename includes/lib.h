/*
** EPITECH PROJECT, 2021
** Lib Header.
** File description:
** Library Header file.
*/

#ifndef LIB_H_
#define LIB_H_

#include <stdarg.h>
#include <stdbool.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_strchr(const char *str, char c);
int number_of_word(char *str, char *pars_characters);
char **str_to_word_tab(char *str, char *pars_characters);
char **init_table(char *str, char *pars_characters);
bool is_valid(char c, char *pars_characters);
int str_compare(char *str1, char *str2);
int str_compare_nolen(char *str1, char *str2);
char *my_inv_strcat(char *dest, char const *src);
int my_strstr_len(char **str);
void tab_char_free(char **str);
char *my_strcpy(char *dest, char const *src);
void print_tab_char(char **str);
char *my_strcat(char *dest, char const *src);
char *characters_cat(char *dest, char *src);
char **init_table_box(char *str, char *pars_characters, int word, char **tab);
void verif_malloc(char **str);

#endif