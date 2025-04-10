##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

INCLUDE_DIR = include

SRC	=	src/delete_elem_linkedlist.c	\
		src/size_command.c				\
		src/print_env.c					\
		src/free_env.c					\
		src/free_list.c					\
		src/find_size_list.c			\
		src/manage_env.c				\
		src/create_linked_list.c		\
		src/main.c						\
		src/my_shell.c					\
		src/parse_commands.c			\
		src/exec_command.c				\
		src/built_in_cd.c				\
		src/unset_env.c					\
		src/set_env.c					\
		src/parse_env.c					\
		src/is_delim.c					\
		src/command.c					\
		src/return_val.c				\
		src/parser_ll/binary_tree.c			\
		src/parser_ll/conditionnal_exec.c	\
		src/parser_ll/double_left.c		\
		src/parser_ll/is_double_right.c	\
		src/parser_ll/is_left.c			\
		src/parser_ll/is_pipe.c			\
		src/parser_ll/is_right.c		\
		src/parser_ll/is_semicolon.c	\
		src/exec_biary_tree/exec_binary_tree.c		\
		src/exec_biary_tree/double_left_exec.c 		\
		src/exec_biary_tree/double_right_exec.c		\
		src/exec_biary_tree/left_exec.c       		\
		src/exec_biary_tree/pipe_exec.c        		\
		src/exec_biary_tree/right_exec.c       		\
		src/exec_biary_tree/semicolon_exec.c   		\
		src/exec_biary_tree/find_the_delim.c		\
		src/exec_biary_tree/copy_arr.c				\
		src/exec_biary_tree/check_builtins.c		\
		src/exec_biary_tree/parse_array.c			\
		src/exec_biary_tree/right_redirections.c

OBJ     =   $(SRC:.c=.o)

NAME    =	mysh

LIB	=	make -C lib/my/

CPPFLAGS += -L lib/my/ -lmy -iquote ./$(INCLUDE_DIR)

CFLAGS += -Wall -Wextra

DEBUG = -g3

all:	$(NAME)

$(NAME): $(OBJ)
	$(LIB)
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS)

debug:	$(OBJ)
	$(LIB)
	$(CC) -o $(NAME) $(DEBUG) $(CFLAGS) $(SRC) $(CPPFLAGS)
clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) coding-style*
	$(RM) *~
	$(RM) *#
	$(RM) *.o
	$(RM) src/*~
	$(RM) src/#*
	$(RM) include/*#
	$(RM) include/*~

fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a
	$(RM) libmy.a
	clear

re:	fclean all

.PHONY: all clean fclean re
