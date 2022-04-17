/*
** EPITECH PROJECT, 2021
** Env file.
** File description:
** Environnement function file.
*/

#include "lib.h"
#include "minishell.h"

void display_env(global_args *list)
{
    for (int i = 0; list->env[i] != NULL; i++) {
        my_putstr(list->env[i]);
        my_putstr("\n");
    }
}

void unset_env(global_args *list)
{
    if (list->cmd[1] == NULL)
        write(2, "unsetenv: Too few arguments.\n", 30);
    else {
        if (list->cmd[1][my_strlen(list->cmd[1])] != '=') {
            list->cmd[1] = characters_cat(list->cmd[1], "=");
            verif_malloc(&list->cmd[1]);
        }
        delete_block(list);
    }
}

void set_env(global_args *list)
{
    if (list->cmd[1] == NULL)
        display_env(list);
    else {
        if (list->cmd[1][my_strlen(list->cmd[1])] != '=') {
            list->cmd[1] = characters_cat(list->cmd[1], "=");
            verif_malloc(&list->cmd[1]);
        }
        edit_block(list);
    }
}

void ctrl_c(int sig)
{
    if (sig == SIGINT)
        my_putstr("\n$> ");
}
