NAME	:=	libft.a
AR		:=	ar
CC 		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -I. -g
SRC		:=	$(wildcard src/mem/*.c) \
			$(wildcard src/string/*.c) \
			$(wildcard src/io/*.c) \
			$(wildcard src/math/*.c) \
			$(wildcard src/list/*.c) \
			$(wildcard src/ctype/*.c) \
			$(wildcard src/vector/*.c) \
			$(wildcard src/stdlib/*.c) \
			$(wildcard src/stack/*.c) \
			$(wildcard src/qsort/*.c) \
			$(wildcard src/queue/*.c) \
			$(wildcard src/get_next_line/*.c) \
			$(wildcard src/ft_getopt_long/*.c) \
			$(wildcard src/printf/*.c) \
			$(wildcard *.c) 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

.PHONY: clean fclean re
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all