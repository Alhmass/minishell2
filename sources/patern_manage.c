/*
** EPITECH PROJECT, 2021
** patern_verificator.
** File description:
** patern_verificator
*/

#include "lib.h"
#include "minishell.h"

int is_script_exec(global_args *list)
{
    if (str_compare_nolen("./", list->cmd[0]) == 1)
        return (verif_file_exec(list));
    else
        return (-1);
}

int verif_file_exec(global_args *list)
{
    int status = open(list->cmd[0] + 2, O_DIRECTORY);

    close(status);
    if (status != -1) {
        write(2, list->cmd[0], my_strlen(list->cmd[0]));
        write(2, ": Permission denied.\n", 22);
    }
    return (status);
}
