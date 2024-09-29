# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 16:59:28 by gsoteldo          #+#    #+#              #
#    Updated: 2023/11/14 18:25:33 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	./src/ft_printf.c \
		./src/ft_printchar.c \
		./src/ft_printinteger.c \
		./src/ft_printpointer.c \
		./src/ft_printstring.c \
		./src/ft_printhexa.c \
		./src/ft_printunsigned.c \
		main.c


OBJ = $(SRC:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@rm -f libft/libft.a
	@mv libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

play: $(NAME)
	$(CC) $(CFLAGS) $(NAME) -o ft_printf
	./ft_printf

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
#	@rm -f libft/libft.a 

re: fclean all

.PHONY: all play clean fclean re 
