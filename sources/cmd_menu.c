/*
** EPITECH PROJECT, 2021
** cmd_menu.
** File description:
** Command menu function file.
*/

#include "lib.h"
#include "minishell.h"
#include "commands.h"

void cmd_menu(global_args *list)
{
    if (list->cmd[0] == NULL)
        return;
    for (int i = 0; COMMAND_MENU[i].command != NULL; i++) {
        if (str_compare_nolen(COMMAND_MENU[i].command, list->cmd[0]) == 1) {
            COMMAND_MENU[i].fpoint(list);
            return;
        }
    }
    exec_command(list);
}
