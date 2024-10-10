# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 19:34:12 by gsoteldo          #+#    #+#              #
#    Updated: 2024/10/10 19:31:10 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	./atoi_itoa_functions/ft_atoi.c \
		./atoi_itoa_functions/ft_itoa.c \
		./fd_functions/ft_putchar_fd.c \
		./fd_functions/ft_putendl_fd.c \
		./fd_functions/ft_putnbr_fd.c \
		./fd_functions/ft_putstr_fd.c \
		./is_functions/ft_isalnum.c \
		./is_functions/ft_isalpha.c \
		./is_functions/ft_isascii.c \
		./is_functions/ft_isdigit.c \
		./is_functions/ft_isprint.c \
		./mem_functions/ft_memchr.c \
		./mem_functions/ft_memcmp.c \
		./mem_functions/ft_memcpy.c \
		./mem_functions/ft_memmove.c \
		./mem_functions/ft_memset.c \
		./others_functions/ft_bzero.c \
		./others_functions/ft_calloc.c \
		./others_functions/ft_split.c \
		./str_functions/ft_strchr.c \
		./str_functions/ft_strdup.c \
		./str_functions/ft_strjoin.c \
		./str_functions/ft_strlcat.c \
		./str_functions/ft_strlcpy.c \
		./str_functions/ft_strlen.c \
		./str_functions/ft_strmapi.c \
		./str_functions/ft_strncmp.c \
		./str_functions/ft_strnstr.c \
		./str_functions/ft_strrchr.c \
		./str_functions/ft_strtrim.c \
		./str_functions/ft_substr.c \
		./str_functions/ft_striteri.c \
		./to_functions/ft_tolower.c \
		./to_functions/ft_toupper.c \

BONUS = ./lst_functions/ft_lstnew_bonus.c \
		./lst_functions/ft_lstadd_front_bonus.c \
		./lst_functions/ft_lstsize_bonus.c \
		./lst_functions/ft_lstlast_bonus.c \
		./lst_functions/ft_lstadd_back_bonus.c \
		./lst_functions/ft_lstdelone_bonus.c \
		./lst_functions/ft_lstclear_bonus.c \
		./lst_functions/ft_lstiter_bonus.c \
		./lst_functions/ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
play: $(NAME)
	$(CC) $(CFLAGS) $(NAME)
	./a.out

all: $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re
