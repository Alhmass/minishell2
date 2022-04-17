/*
** EPITECH PROJECT, 2021
** Minishell program file.
** File description:
** minishell
*/

#include "lib.h"
#include "minishell.h"

void init_struct(global_args *list, char **env)
{
    copy_env(list, env);
    list->exit = 0;
}

void start_shell(char **env)
{
    global_args *list = malloc(sizeof(global_args));

    if (list == NULL)
        exit(84);
    signal(SIGINT, ctrl_c);
    init_struct(list, env);
    while (list->exit == 0) {
        my_putstr("$> ");
        if (get_next_line(list) == -1)
            exit_shell(list);
        else {
            get_path(list);
            cmd_exec_loop(list);
            if (list->path != NULL)
                tab_char_free(list->path);
        }
    }
    tab_char_free(list->env);
    free(list);
}