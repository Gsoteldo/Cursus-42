# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:53:47 by gsoteldo          #+#    #+#              #
#    Updated: 2024/03/31 18:06:16 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

NAME = minitalk
NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

#Clientes
SRC_CLIENT = client.c

SRC_CLIENT_BONUS = client_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

#Servidores
SRC_SERVER = server.c

SRC_SERVER_BONUS = server_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

#Main rules
all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	@make -s -C libft

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@echo "Compilando cliente..."
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -L libft -lft -o $(NAME_CLIENT)
	@echo "$(GREEN)-----------------Cliente Compilado-----------------$(NC)"

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@echo "Compilando servidor..."
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -L libft -lft -o $(NAME_SERVER)
	@echo "$(GREEN)------------------Server Compilado------------------$(NC)"

clean:
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@rm -f $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@make clean -C libft

fclean: clean
	@rm -f client server
	@make fclean -C libft
	@echo "$(RED)-----------------Borrado cliente y/o servidor-----------------$(NC)"

re: fclean all

#Bonus
bonus: client_bonus server_bonus

client_bonus: $(OBJ_CLIENT_BONUS) $(LIBFT)
	@echo "Compilando cliente bonus..."
	@$(CC) $(OBJ_CLIENT_BONUS) -L libft -lft -o $(NAME_CLIENT)
	@echo "$(GREEN)--------------------Cliente Compilado--------------------$(NC)"

server_bonus: $(OBJ_SERVER_BONUS) $(LIBFT)
	@echo "Compilando servidor bonus..."
	@$(CC) $(OBJ_SERVER_BONUS) -L libft -lft -o $(NAME_SERVER)
	@echo "$(GREEN)--------------------Servidor Compilado--------------------$(NC)"

re_bonus: fclean bonus
	
.PHONY: all clean fclean re bonus