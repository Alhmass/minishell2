/*
** EPITECH PROJECT, 2021
** Command header file.
** File description:
** Header file.
*/

#ifndef COMMANDS
#define COMMANDS

#include "minishell.h"

const struct insert_command COMMAND_MENU[] =
{
    {"env", &display_env},
    {"exit", &exit_shell},
    {"cd", &content_file},
    {"unsetenv", &unset_env},
    {"setenv", &set_env},
    {NULL, NULL}
};

#endif
