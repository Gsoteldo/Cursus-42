# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 16:59:28 by gsoteldo          #+#    #+#              #
#    Updated: 2024/02/24 16:28:29 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC =	./src/push_swap.c \
		./src/cheap.c \
		./src/check_input.c \
		./src/free_stacks.c \
		./src/max_min_values.c \
		./src/moves_a.c \
		./src/moves_b.c \
		./src/push.c \
		./src/reverse_rotate.c \
		./src/rotate.c \
		./src/sort_3_numbers.c \
		./src/sort_4_numbers.c \
		./src/stack.c \
		./src/swap.c \
		./src/utils.c \

OBJ = $(SRC:.c=.o)

SRC_BONUS = ./bonus/checker_bonus.c \
			./bonus/check_input_bonus.c \
			./bonus/free_stacks_bonus.c \
			./bonus/push_bonus.c \
			./bonus/reverse_rotate_bonus.c \
			./bonus/rotate_bonus.c \
			./bonus/stack_bonus.c \
			./bonus/stack_bonus.c \
			./bonus/swap_bonus.c \

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@mv libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

bonus: $(OBJ_BONUS)
	@make -C libft
	@mv libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(NAME) -o checker

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f push_swap
	rm -f checker

re: fclean all

re_bonus: fclean bonus

.PHONY: all play clean fclean re bonus
