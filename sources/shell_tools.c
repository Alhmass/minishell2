/*
** EPITECH PROJECT, 2021
** shell_tools.
** File description:
** shell_tools
*/

#include "lib.h"
#include "minishell.h"

void get_path(global_args *list)
{
    char *path;

    for (int i = 0; list->env[i] != NULL; i++) {
        if (str_compare_nolen("PATH=", list->env[i]) == 1) {
            path = malloc(sizeof(char) * (my_strlen(list->env[i] + 5) + 1));
            path = my_strcpy(path, list->env[i] + 5);
        }
    }
    if (path == NULL)
        list->path = NULL;
    else {
        list->path = str_to_word_tab(path, ":");
        verif_malloc(list->path);
        free(path);
    }
}

int get_next_line(global_args *list)
{
    char *str;
    size_t input_size = 10;
    char **str_ptr = &str;
    int verif_return = 0;

    str = malloc(sizeof(char) * input_size);
    verif_malloc(&str);
    verif_return = getline(str_ptr, &input_size, stdin);
    if (verif_return == -1) {
        free(str);
        return (verif_return);
    }
    str[my_strlen(str) - 1] = '\0';
    list->cmd_list = str_to_word_tab(str, ";");
    free(str);
    return (0);
}

void copy_env(global_args *list, char **env)
{
    list->env = malloc(sizeof(char *) * (my_strstr_len(env) + 1));
    verif_malloc(list->env);
    for (int k = 0; env[k] != NULL; k++) {
        list->env[k] = malloc(sizeof(char) * (my_strlen(env[k]) + 1));
        verif_malloc(&list->env[k]);
        my_strcpy(list->env[k], env[k]);
    }
    list->env[my_strstr_len(env)] = NULL;
}

void cmd_exec_loop(global_args *list)
{
    for (int i = 0; list->cmd_list[i] != NULL; i++) {
        list->cmd = str_to_word_tab(list->cmd_list[i], " \t");
        cmd_menu(list);
        tab_char_free(list->cmd);
    }
    tab_char_free(list->cmd_list);
}