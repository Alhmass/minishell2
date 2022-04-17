/*
** EPITECH PROJECT, 2021
** redirection
** File description:
** redirection
*/

#include "lib.h"
#include "minishell.h"

int add_to_file(char *filepath)
{
    int fd = open(filepath, O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        write(2, "Missing name for redirect.\n", 28);
        return (84);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return (0);
}

int add_to_endfile(char *filepath)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        write(2, "Missing name for redirect.\n", 28);
        return (84);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return (0);
}

int redirect_cmd(global_args *list)
{
    int status = 0;

    for (int i = 0; list->cmd[i] != NULL; i++){
        if (str_compare(">", list->cmd[i]) == 1) {
            status = add_to_file(list->cmd[i + 1]);
            list->cmd[i] = NULL;
        }
        else if (str_compare(">>", list->cmd[i]) == 1) {
            status = add_to_endfile(list->cmd[i + 1]);
            list->cmd[i] = NULL;
        }
    }
    return (status);
}
