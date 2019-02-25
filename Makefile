NAME	:=	ft_ls
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -g -fsanitize=address -Iincludes
LDFLAGS	:=	-Llibs/libft -lft

SRC :=	$(wildcard src/ls_core/*.c) \
		$(wildcard src/ls_opts_and_arg/*.c) \
		$(wildcard src/ls_printing/*.c) \
		$(wildcard src/ls_sorting_functions/*.c)

OBJ := $(SRC:.c=.o)

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
