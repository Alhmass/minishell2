/*
** EPITECH PROJECT, 2021
** cmd.
** File description:
** Cmd function file.
*/

#include "lib.h"
#include "minishell.h"

void exec_command(global_args *list)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1)
        perror("fork() error");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        print_exit_error(status);
        kill(pid, SIGTERM);
    } else {
        if (verif_exec(list) == 1) {
            write(2, list->cmd[0], my_strlen(list->cmd[0]));
            write(2, ": Command not found.\n", 21);
        }
        exit(0);
    }
}

int verif_exec(global_args *list)
{
    if (redirect_cmd(list) == 84)
        return (0);
    else if (execve(list->cmd[0], list->cmd, list->env) != -1 ||
            is_script_exec(list) != -1)
        return (0);
    else if (exec_path(list) == 0)
        return (0);
    return (1);
}

void print_exit_error(int status)
{
    if (WTERMSIG(status) == 11)
        my_putstr("Segmentation fault");
    else if (WTERMSIG(status) == 8)
        my_putstr("Floating exception");
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    else
        return;
    my_putstr("\n");
}

void exit_shell(global_args *list)
{
    my_putstr("exit\n");
    list->exit = 1;
}
