/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-hugo.lumet
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell_struct.h"
#include <sys/stat.h>
#include <fcntl.h>

extern const struct insert_command COMMAND_MENU[];
void get_path(global_args *list);
void content_file(global_args *list);
void cmd_menu(global_args *list);
void init_struct(global_args *list, char **env);
void exec_command(global_args *list);
int verif_exec(global_args *list);
void display_env(global_args *list);
int get_next_line(global_args *list);
void start_shell(char **env);
void exit_shell(global_args *list);
void unset_env(global_args *list);
void delete_block(global_args *list);
void copy_env(global_args *list, char **env);
void add_character(global_args *list);
void print_exit_error(int status);
char *init_copyarg(global_args *list, char *copy_arg);
void edit_block(global_args *list);
void set_env(global_args *list);
void add_block(global_args *list);
char *init_new_block(global_args *list);
void ctrl_c(int sig);
char *get_directory(global_args *list, char *dir);
void print_cd_error(global_args *list);
int is_script_exec(global_args *list);
int verif_file_exec(global_args *list);
void cmd_exec_loop(global_args *list);
int redirect_cmd(global_args *list);
int add_to_file(char *filepath);
int add_to_endfile(char *filepath);
int exec_path(global_args *list);
char *path_create_command(global_args *list, char *path_cmd, int pos);

#endif