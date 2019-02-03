
NAME	= t 

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB_FLAGS	= -L./libft -lft

all:	$(NAME)


$(NAME):
		$(CC) $(CFLAGS) ./srcs/ft_printf.c test_printf.c $(LIB_FLAGS) -o $(NAME)
clean:
	@rm -rf	$(NAME)

fclean: clean

re:
	@$(MAKE) fclean
	@$(MAKE) all
