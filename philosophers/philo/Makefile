# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 17:06:58 by gabo              #+#    #+#              #
#    Updated: 2024/08/19 19:21:32 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(SRC))


NAME = philo

SRC = philo.c \
	checker.c \
	utils.c \
	initialization.c \
	routine.c \
	monitoring.c \
	thread_management.c \

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