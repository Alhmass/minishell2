/*
** EPITECH PROJECT, 2021
** Block_editor.
** File description:
** Function that edit block.
*/

#include "lib.h"
#include "minishell.h"

void edit_block(global_args *list)
{
    for (int i = 0; list->env[i] != NULL; i++) {
        if (str_compare_nolen(list->cmd[1], list->env[i]) == 1
                && list->cmd[2] != NULL) {
            free(list->env[i]);
            list->env[i] = characters_cat(list->cmd[1], list->cmd[2]);
            verif_malloc(&list->env[i]);
            return;
        }
        else if (str_compare_nolen(list->cmd[1], list->env[i]) == 1) {
            free(list->env[i]);
            list->env[i] = malloc(sizeof(char) * (my_strlen(list->cmd[1]) + 1));
            verif_malloc(&list->env[i]);
            list->env[i] = my_strcpy(list->env[i], list->cmd[1]);
            return;
        }
    }
    add_block(list);
}

void add_block(global_args *list)
{
    char **copy_env;
    char *new_block = init_new_block(list);
    int k = 0;

    copy_env = malloc(sizeof(char *) *
            ((my_strstr_len(list->env) + my_strlen(new_block)) + 1));
    verif_malloc(copy_env);
    while (list->env[k] != NULL) {
        copy_env[k] = malloc(sizeof(char) * (my_strlen(list->env[k]) + 1));
        verif_malloc(&copy_env[k]);
        my_strcpy(copy_env[k], list->env[k]);
        k++;
    }
    copy_env[k] = new_block;
    copy_env[k + 1] = NULL;
    tab_char_free(list->env);
    list->env = copy_env;
}

char *init_new_block(global_args *list)
{
    char *new_block;

    if (list->cmd[2] == NULL) {
        new_block = malloc(sizeof(char) * (my_strlen(list->cmd[1]) + 1));
        verif_malloc(&new_block);
        new_block = my_strcpy(new_block, list->cmd[1]);
    }
    else {
        new_block = characters_cat(list->cmd[1], list->cmd[2]);
        verif_malloc(&new_block);
    }
    return (new_block);
}

void delete_block(global_args *list)
{
    char **copy_env;
    int q = 0;

    copy_env = malloc(sizeof(char *) * (my_strstr_len(list->env) + 1));
    verif_malloc(copy_env);
    for (int k = 0; list->env[k] != NULL; k++) {
        if (str_compare_nolen(list->cmd[1], list->env[k]) == 0) {
            copy_env[q] = malloc(sizeof(char) * (my_strlen(list->env[k]) + 1));
            verif_malloc(&copy_env[q]);
            my_strcpy(copy_env[q], list->env[k]);
            q++;
        }
    }
    copy_env[q] = NULL;
    tab_char_free(list->env);
    list->env = copy_env;
}
