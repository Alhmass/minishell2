#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	sources/main.c \
		sources/cmd.c \
		sources/env.c \
		sources/minishell.c \
		sources/cmd_menu.c \
		sources/block_editor.c \
		sources/cd_builtin.c \
		sources/patern_manage.c \
		sources/shell_tools.c \
		sources/redirection.c \
		sources/exec.c


OBJ = 	$(SRC:.c=.o)

NAME = mysh

LDFLAGS = -L./sources/lib/

LDLIBS = -lmy

CPPFLAGS = -I./includes

CFLAGS = -Wall -Wextra -g

all: $(NAME)

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C sources/lib/

clean:
	make clean -C sources/lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C sources/lib/
	rm -f $(NAME)

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib
