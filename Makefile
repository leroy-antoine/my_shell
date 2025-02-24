##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

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
		src/command.c					\

OBJ     =   $(SRC:.c=.o)

NAME    =	mysh

LIB	=	make -C lib/my/

CPPFLAGS += -iquote./include

CFLAGS += -Wall -Wextra

VALGRIND = -g3

all:	$(OBJ)
	$(LIB)
	$(CC)  -o $(NAME) $(SRC) -L lib/my/ -lmy $(CPPFLAGS)

val:	$(OBJ)
	$(LIB)
	$(CC) -o $(NAME) $(VALGRIND) $(CFLAGS) $(SRC) -L lib/my/ -lmy $(CPPFLAGS)
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

re:	fclean all

.PHONY: all clean fclean re
