/*
** EPITECH PROJECT, 2021
** main.
** File description:
** Main file minishell1.
*/

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    (void) argc;
    (void) argv;
    start_shell(env);
    return (0);
}