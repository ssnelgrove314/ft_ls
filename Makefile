NAME	:=	ft_ls
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
DEBUG	:=	-g -fsanitize=address -L/usr/lib/gcc/x86_64-pc-linux-gnu/8.2.1 -lgcc
LDFLAGS	:=	-Llibs/libft -lft

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(DEBUG) $(LDFLAGS)

.PHONY: libft
libft:
	$(MAKE) -C libs/libft

.PHONY: clean fclean re
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all