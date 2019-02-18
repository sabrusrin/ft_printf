# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 20:03:10 by chermist          #+#    #+#              #
#    Updated: 2019/02/18 22:48:49 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= libftprintf.a

SRCS = ./srcs/ft_printf.c \
		./srcs/libft/ft.c \
		./srcs/support/flags_exe.c \
		./srcs/support/spec_exe.c \
		./srcs/support/assist.c \
		./srcs/support/parse.c

INCLUDES = ./includes/ft_printf.h \
			./includes/ft_sup.h

OBJ = $(SRCS:%.c=%.o)

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c $(INCLUDES)
		@$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -f	$(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
