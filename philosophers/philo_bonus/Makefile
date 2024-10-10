# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 18:37:05 by gsoteldo          #+#    #+#              #
#    Updated: 2024/08/26 13:18:53 by gabo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(SRC))


NAME = philo_bonus

SRC = philo_bonus.c \
	checker_bonus.c \
	utils_bonus.c \
	initialization_bonus.c \
	process_management_bonus.c \
	routine_bonus.c \
	monitoring_bonus.c \
	ft_itoa_join_bonus.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g3

CFLAGS = -Wall -Wextra -Werror

all: show_progress $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)It has been compiled, have a nice day.👍$(NC)";

%.o: %.c
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "Compiling $<... $(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES))))%%\r"
	@$(CC) $(CFLAGS) -c $< -o $@

show_progress:
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)The compiled code is already updated.$(NC)"; \
	fi

git:
	git add *
	git commit
	git push

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Full Cleaning...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Full Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re