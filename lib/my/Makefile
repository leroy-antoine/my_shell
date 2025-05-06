##
## EPITECH PROJECT, 2024
## makefile
## File description:
## root makefile
##

SRC =	my_str_to_word_array.c		\
		my_is_number.c				\
		my_intlen.c					\
		free_list.c					\
		my_list_len.c				\
		dup_list.c					\
		my_strcat_inf.c				\
		my_strdup_delim.c			\
		my_free.c					\
		is_file.c					\
		open_file.c					\
		help.c						\
		array.c              		\
		copy_array.c					\
		get_file_lines_nb.c 		\
		get_to_nth_line.c 			\
		is_int_float.c 				\
		my_revstrndup.c				\
		my_free_str.c				\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS = -iquote ../../include

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all	clean fclean re
