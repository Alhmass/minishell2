/*
** EPITECH PROJECT, 2021
** exec.
** File description:
** exec
*/

#include "lib.h"
#include "minishell.h"

int exec_path(global_args *list)
{
    char *copy;

    if (list->path == NULL) return (1);
    copy = malloc(sizeof(char) * (my_strlen(list->cmd[0]) + 1));
    verif_malloc(&copy);
    for (int i = 0; list->path[i] != NULL; i++) {
        copy = path_create_command(list, copy, i);
        if (execve(copy, list->cmd, list->env) != -1) {
            free(copy);
            return (0);
        }
    }
    free(copy);
    return (1);
}

char *path_create_command(global_args *list, char *path_cmd, int pos)
{
    path_cmd = my_strcpy(path_cmd, list->cmd[0]);
    list->path[pos] = characters_cat(list->path[pos], "/");
    verif_malloc(&list->path[pos]);
    path_cmd = my_inv_strcat(list->cmd[0], list->path[pos]);
    verif_malloc(&path_cmd);
    return (path_cmd);
}
