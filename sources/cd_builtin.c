/*
** EPITECH PROJECT, 2021
** cd_builtin.
** File description:
** cd_builtin
*/

#include "lib.h"
#include "minishell.h"
#include <errno.h>

void content_file(global_args *list)
{
    int state = 0;

    if (list->cmd[1] == NULL)
        state = chdir(get_directory(list, "HOME="));
    else if (str_compare("cd-", list->cmd[0]) == 1 ||
            str_compare("-", list->cmd[1]) == 1)
        state = chdir(get_directory(list, "OLDPWD="));
    else
        state = chdir(list->cmd[1]);
    if (state == -1)
        print_cd_error(list);
}

void print_cd_error(global_args *list)
{
    if (errno == ENOENT) {
        write(2, list->cmd[1], my_strlen(list->cmd[1]));
        write(2, ": No such file or directory.\n", 30);
    }
    else if (errno == ENOTDIR) {
        write(2, list->cmd[1], my_strlen(list->cmd[1]));
        write(2, ": Not a directory.\n", 20);
    }
    else
        write(2, ": No such file or directory.\n", 30);
}

char *get_directory(global_args *list, char *dir)
{
    for (int i = 0; list->env[i] != NULL; i++) {
        if (str_compare_nolen(dir, list->env[i]) == 1)
            return (list->env[i] + my_strlen(dir));
    }
    return (NULL);
}
