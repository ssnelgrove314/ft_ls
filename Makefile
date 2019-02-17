NAME	:=	ft_ls
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -g -fsanitize=address
LDFLAGS	:=	-Llibs/libft -lft

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: libft
libft:
	$(MAKE) -C libs/libft

.PHONY: clean fclean re
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
