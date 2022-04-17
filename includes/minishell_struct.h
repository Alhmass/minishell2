/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-hugo.lumet
** File description:
** minishell_struct
*/

#ifndef MINISHELL_STRUCT_H_
#define MINISHELL_STRUCT_H_

typedef struct global_args
{
    char **cmd;
    char **cmd_list;
    int exit;
    char **env;
    char **path;
} global_args;

typedef struct insert_command
{
    char *command;
    void (*fpoint)(global_args *);
} insert_command;

#endif
